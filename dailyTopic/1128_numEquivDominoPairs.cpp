#include <iostream>
#include <vector>
#include <iterator>


using namespace std;

// https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs/
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int pairNum = 0;
        vector<int> num(100);
        // 每增加一个新的相同映射对, 相当于增加了 已有映射对数 的组合
        // 如果 12 之前出现了 m 次，那么新加入的 12 就能再多贡献 m 个匹配对数
        for (auto item : dominoes) {
            int val =   item[0]> item[1] ? item[0]*10 + item[1] : item[0] + item[1]*10;
            pairNum += num[val];
            ++num[val];
        }
        return pairNum;
    }
};

int main() {
    // vector<int> num{1,3,5,4,7};
    // vector<vector<int>> dominoes = {{1,2}, {2,1}, {3,4}, {1,2}, {4,3}};
    vector<vector<int>> dominoes = {{1,2}, {2,1}, {1,2}, {1,2}};
    cout << Solution().numEquivDominoPairs(dominoes) << endl;
    return 0;
}
