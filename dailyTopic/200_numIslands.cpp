#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
using namespace std;


// https://leetcode-cn.com/problems/island-perimeter/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // return islandPerimeter_2(grid);
        return bfs(grid);
    }


    int bfs(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++res;
                    grid[i][j] = '0';
                    queue<pair<int, int>> neighbors;
                    neighbors.push({i, j});
                    while (!neighbors.empty()) {
                        auto rc = neighbors.front(); neighbors.pop();
                        int row = rc.first, col = rc.second;
                        // left
                        if (row-1 >= 0 && grid[row-1][col] == '1') {
                            neighbors.push({row-1, col});
                            grid[row-1][col] = '0';
                        }
                        // right
                        if (col+1 < grid[0].size() && grid[row][col+1] == '1') {
                            neighbors.push({row, col+1});
                            grid[row][col+1] = '0';
                        }
                        // up
                        if (col-1 >= 0 && grid[row][col-1] == '1') {
                            neighbors.push({row, col-1});
                            grid[row][col-1] = '0';
                        }
                         // down
                        if (row+1 < grid.size() && grid[row+1][col] == '1') {
                            neighbors.push({row+1, col});
                            grid[row+1][col] = '0';
                        }
                    }
                }
            }
        }
        return res;
    }


    // 遍历岛这个二维数组，如果当前数为1，则进入感染函数并将岛个数+1
    int islandPerimeter_2(vector<vector<char>>& grid) {
        int res = 0 ;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++res;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int r, int c) {
        // 超过边界，直接返回
        if(!(r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size())) {
            return;
        }
        // 不为岛，直接返回
        if (grid[r][c] != '1') {
            return ;
        }

        grid[r][c] = '2';     // 将方格标记为"已遍历"
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }
};


void print_vec(const vector<vector<char>>& vec){
    for(auto res: vec) {
        copy(res.begin(), res.end(), ostream_iterator<char>(cout, " "));
        std::endl(std::cout);
    }
    cout << endl;
}


int main() {

    vector<vector<char>> nums = {{'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'}};
    print_vec(nums);
    cout <<  Solution().numIslands(nums);

    return 0;
}
