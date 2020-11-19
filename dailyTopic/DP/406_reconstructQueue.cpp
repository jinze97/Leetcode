#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

// https://leetcode-cn.com/problems/queue-reconstruction-by-height/
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // return reconstructQueue_1(people);
        // return reconstructQueue_2(people);
        return reconstructQueue_3(people);
    }

    // 先对输入数组排序，h升序，k降序
    // 从头循环遍历 当前这个人就是剩下未安排的人中最矮的人，
    // 他的k值就代表他在 剩余空位 的索引值
    // 如果有多个人高度相同，要按照k值从大到小领取索引值
    vector<vector<int>> reconstructQueue_2(vector<vector<int>>& people) {
        // 从小到大排序, 相等按第二个反序
        sort(people.begin(), people.end(), [&](const vector<int> u, const vector<int> v) {
            // return u[0] == v[0] ? u[1] < v[1] : u[0] > v[0];
            return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
        });
        int n = people.size();
        vector<vector<int>> ans(n);

        // 构建 1-n的数组
        vector<int> ord(n);
        for (int i = 0; i < n; i++) {
            ord[i] = i;
        }

        // 从排序好的数组里面， 每次取得的是未排序的最矮的元素
        // 将它插入到ans数组里 “第i个还没有被填过的坑”
        for (int i = 0; i < n; ++i) {
            copy(ord.begin(), ord.end(), ostream_iterator<int>(cout, " "));
            cout << endl;
            int index = people[i][1];
            index = ord[index];

            ans[index] = people[i];

            // 删除以被占位的下标
            ord.erase(ord.begin() + people[i][1]);
        }
        return ans;
    }


    vector<vector<int>> reconstructQueue_1(vector<vector<int>>& people) {
        // 从大到小排序， 相同的按第二个元素升序排序
        // 对于每个元素，在其之前的元素的个数，就是大于等于他的元素的数量
        // 第二个元素正向排序，我们希望 k 大的尽量在后面，减少插入操作的次数
        sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
            // return u[0] == v[0] ? u[1] < v[1] : u[0] > v[0];
            return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
        });

        int n = people.size();
        vector<vector<int>> ans;
        for (const vector<int>& person: people) {
            ans.insert(ans.begin() + person[1], person);
        }
        return ans;


        // // 身高高的先被插入，k小的先被插入，
        // // 那么身高矮的进来时，高的已经占有了位置，矮的前面自然都是高的了
        // list<vector<int>> ans;
        // for (const vector<int>& person: people) {
        //     // auto it = ans.begin();
        //     // advance(it, person[1]);
        //     // ans.insert(it, person);
        //     // or
        //     ans.insert(next(begin(ans), person[1]), person);
        // }
        // return vector<vector<int>>(begin(ans), end(ans));



    }


    // 动态规划
    vector<vector<int>> reconstructQueue_3(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [&](const vector<int> u, const vector<int> v) {
            // return u[0] == v[0] ? u[1] > v[1] : u[0] < v[0];
            return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
        });
        vector<vector<int>>ans(n);
        vector<bool>dp(n);
        for (int i = 0; i != n; ++i) {
            int t = 0;
            for (int b = 0; b != n; ++b) {
                if (dp[b] == 0) {
                    if (t == people[i][1]) {
                        dp[b] = 1;
                        ans[b] = people[i];
                        break;
                    }
                    ++t;
                }
            }
        }
        return ans;
    }
};


void print_vec(const vector<vector<int>>& vec){
    for(auto res: vec) {
        std::cout << '[';
        copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
        std::cout << "] ";
    }
    std::endl(std::cout);
}


int main() {
    vector<vector<int>> nums = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    print_vec(nums);
    auto res = Solution().reconstructQueue(nums);
    print_vec(res);
    return 0;
}
