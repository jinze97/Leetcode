#include <iostream>
#include <vector>
#include <numeric>  //iota


using namespace std;

// https://leetcode-cn.com/problems/number-of-provinces/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        std::vector<int> parent(n);
        std::vector<int> size(n);   // 记录每个根(以自身作为根)节点对应的树的深度

        iota(parent.begin(),parent.end(),0);
        // for (int i = 0; i < n; ++i) {
        //     parent[i] = i;
        // }

        for (int i = 0; i < isConnected.size(); ++i) {
            for (int j = 0; j < isConnected.size(); ++j) {
                if (isConnected[i][j] == 1) {
                    unionSet(i, j, parent, size);   // 相连的省份合并
                }
            }
        }

        int circles = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                circles++;
            }
        }
        return circles;
    }

    // 合并两个族
    void unionSet(int u, int v, std::vector<int>& parent, std::vector<int>& size) {
        int x = find(u, parent);
        int y = find(v, parent);
        if (x == y) {
            return;
        }
        // 保证小的合到大的里 (把简单的树往复杂的树上合并)
        if (size[x] > size[y]) {
            swap(x, y);
        }
        parent[x] = y;
        size[y] += size[x];
    }


    // 寻找根节点
    int find(int x, std::vector<int>& parent) {
        if (x != parent[x]) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
        // return x == parent[x] ? x : (parent[x] = find(parent[x]));
    }
};


int main() {
    vector<vector<int>> isConnected  = {{1,1,0}, {1,1,0}, {0,0,1}};
    cout << Solution().findCircleNum(isConnected) << endl;
    return 0;
}
