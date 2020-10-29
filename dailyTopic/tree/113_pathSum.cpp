#include <iostream>
#include <queue>
#include <vector>
#include <iterator>
#include <algorithm>
#include <unordered_map>

#include "tools_tree.cpp"

using namespace std;


// https://leetcode-cn.com/problems/path-sum-ii/
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        // return bfs(root, sum);

        result.clear();
        vector<int> path;
        if (!root) return result;
        dfs(root, sum, path);
        return result;
    }

    // 根据parent表获得路径
    void getPath(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent) {
        vector<int> tmp;
        while (node != nullptr) {
            tmp.emplace_back(node->val);
            node = parent[node];
        }
        reverse(tmp.begin(), tmp.end());
        result.emplace_back(tmp);
    }


    vector<vector<int>> bfs(TreeNode* node, int sum) {
        if (!node) {
            return result;
        }
        unordered_map<TreeNode*, TreeNode*> parent;     // 记录每个节点的父节点
        stack<pair<TreeNode*, int>> nodeStack;          // 记录当前节点，与到当前结点的和
        nodeStack.push(pair<TreeNode*, int>(node, node->val));

        while (!nodeStack.empty()) {
            pair<TreeNode*, int> node = nodeStack.top(); nodeStack.pop();
            TreeNode* left = node.first->left, *right = node.first->right;
            // 叶子节点并且值相等
            if (!left && !right  && node.second == sum ) {
                getPath(node.first, parent);  // 记录路径
                continue;
            }
            if (right) {
                parent[right] = node.first;
                nodeStack.push(pair<TreeNode*, int>(right, node.second + right->val));
            }
            if (left) {
                parent[left] = node.first;
                nodeStack.push(pair<TreeNode*, int>(left, node.second  + left->val));
            }
        }
        return result;
    }


    void dfs(TreeNode* node, int sum, vector<int> &path) {
        path.push_back(node->val);      // 将当前节点加入路径
        if (!node->left && !node->right && sum == node->val) {   // 遇到了叶子节点切找到了和为sum的路径
            result.push_back(path);
            return;
        }
        if (!node->left && !node->right) {  // 遇到叶子节点而没有找到合适的边，直接返回
            return;
        }

        if (node->left) {
            dfs(node->left, sum - node->val, path);
            path.pop_back();                   // 回溯
        }

        if (node->right) {
            dfs(node->right, sum - node->val, path);
            path.pop_back();                    // 回溯
        }
        return;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    std::vector<int> Data{5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1};
    TreeNode* Root = NULL;
    Root = createBinaryTree(Data);
    levelOrder(Root);
    vector<vector<int>> res = Solution().pathSum(Root, 22);
    for (auto i: res) {
        cout << '[';
        copy(i.begin(), i.end(), ostream_iterator<int>(cout, " "));
        cout << ']' << endl;
    }
    // copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
