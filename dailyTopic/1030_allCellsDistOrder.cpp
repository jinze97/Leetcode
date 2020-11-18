#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
using namespace std;

// https://leetcode-cn.com/problems/matrix-cells-in-distance-order/
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        // return allCellsDistOrder_1(R, C, r0, c0);
        // return BFS(R, C, r0, c0);
        return bucketSort(R, C, r0, c0);
    }

    // 直接排序
    vector<vector<int>> allCellsDistOrder_1(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                res.push_back({i, j});
            }
        }
        sort(res.begin(), res.end(), [&](const vector<int> a, const vector<int> b) {
            return abs(a[0] - r0) + abs(a[1] - c0) < abs(b[0] - r0) + abs(b[1] - c0);
        });
        return res;
    }


    vector<vector<int>>  BFS(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        // 记录已访问元素
        vector<vector<bool>> visited(R, vector<bool>(C, false));

        int ax[] = {1, 0, -1, 0};
        int ay[] = {0, 1, 0, -1};

        queue<pair<int, int>> neighbors;
        neighbors.push({r0, c0});
        visited[r0][c0] = true;
        while (!neighbors.empty()) {
            auto rc = neighbors.front(); neighbors.pop();
            int x = rc.first, y = rc.second;
            res.push_back({x, y});

            // if (x + 1 < R && )
            for(int i = 0; i < 4; ++i) {
                int newx = x + ax[i];
                int newy = y + ay[i];
                // 有效索引并且未访问过
                if(newx >= 0 && newx < R && newy >=0 && newy < C && visited[newx][newy] == 0) {
                    neighbors.push({newx, newy});
                    visited[newx][newy] = 1;
                }
            }

        }
        return res;
    }



    /*
     * 桶排序的核心: 确定有几个桶?
     * 在这道题中, 我们定义最大曼哈顿距离 + 1 个桶, 每个桶代表一个曼哈顿距离
     * 并存放曼哈顿距离等于这个桶的曼哈顿距离的{i, j}.
       那么, 最后直接按桶的顺序返回结果集即可
    */
    vector<vector<int>> bucketSort(int R, int C, int r0, int c0) {
        int maxDist = max(r0, R - 1 - r0) + max(c0, C - 1 - c0);  //最大曼哈顿距离
        vector<vector<vector<int>>> bucket(maxDist + 1);  //桶排序

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int d = abs(i - r0) + abs(j - c0);  //计算曼哈顿距离
                bucket[d].emplace_back(vector<int>{i, j});
            }
        }

        vector<vector<int>> ret;
        for (int i = 0; i <= maxDist; i++) {
            for (auto &it : bucket[i]) {
                ret.push_back(it);     //遍历所有桶, 并把每个桶的元素放入结果集
            }
        }
        return ret;
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
    int R = 1, C = 2, r0 = 0, c0 = 1;
    auto res = Solution().allCellsDistOrder(R, C, r0, c0);
    print_vec(res);
    return 0;
}
