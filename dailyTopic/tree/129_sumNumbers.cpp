#include <iostream>
#include <queue>

#include "tools_tree.cpp"

using namespace std;


// https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/
class Solution {
public:
    int sumNumbers(TreeNode* root) {

        // return dfs(root, 0);
        return bfs(root);
    }

    // 广度优先
    int bfs(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }
        int sum = 0;
        queue<pair<TreeNode*, int>> nodeQueue;  // 记录当前节点，与值
        nodeQueue.push(pair<TreeNode*, int>(root, root->val));

        while (!nodeQueue.empty()) {
            pair<TreeNode*, int> node = nodeQueue.front(); nodeQueue.pop();
            TreeNode* left = node.first->left, *right = node.first->right;
            if (left == nullptr && right == nullptr) {
                sum += node.second;
            } else {
                if (left) {
                    nodeQueue.push(pair<TreeNode*, int>(left, node.second*10 + left->val));
                }
                if (right) {
                    nodeQueue.push(pair<TreeNode*, int>(right, node.second*10 + right->val));
                }
            }
        }
        return sum;
    }


    int dfs(TreeNode* root, int preSum) {
        if (nullptr == root){
            return 0;
        }
        int sum = preSum*10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return sum;
        } else {
            return dfs(root->left, sum) + dfs(root->right, sum);
        }
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    std::vector<int> Data{1,2,3};
    TreeNode* Root = NULL;
    Root = createBinaryTree(Data);
    levelOrder(Root);
    ::cout << Solution().sumNumbers(Root);
    // copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
