#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <iterator>
using namespace std;


// https://leetcode-cn.com/problems/island-perimeter/
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // return islandPerimeter_1(grid);
        return islandPerimeter_2(grid);
    }

    int islandPerimeter_1(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    res += 4;
                    // 只要前面有相邻的方格，就-2
                    if (i > 0 && grid[i-1][j] == 1) {
                        res -= 2;
                    }
                    if (j > 0 && grid[i][j-1] == 1) {
                        res -= 2;
                    }
                }
            }
        }
        return res;
    }

    int islandPerimeter_2(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                     return dfs(grid, i, j);
                }
            }
        }
        return 0;
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
        // 从一个岛屿方格走向网格边界，周长加 1
        if(!(r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size())) {
            return 1;
        }

        // 从一个岛屿方格走向水域方格，周长加 1
        if (grid[r][c] == 0) {
            return 1;
        }

        // 已遍历过（值为2）的岛屿在这里会直接返回，不会重复遍历
        if (grid[r][c] != 1) {
            return 0;
        }
        grid[r][c] = 2;     // 将方格标记为"已遍历"

        int left = dfs(grid, r - 1, c);
        int right = dfs(grid, r + 1, c);
        int up = dfs(grid, r, c - 1);
        int down = dfs(grid, r, c + 1);
        return left + right + up + down;
    }
};


void print_vec(const vector<vector<int>>& vec){
    for(auto res: vec) {
        copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
        std::endl(std::cout);
    }
    cout << endl;
}


int main() {

    vector<vector<int>> nums = {{0,1,0,0}, {1,1,1,0}, {0,1,0,0}, {1,1,0,0}};
    print_vec(nums);
    cout <<  Solution().islandPerimeter(nums);

    return 0;
}
