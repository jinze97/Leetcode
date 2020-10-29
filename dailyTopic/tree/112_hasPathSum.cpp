#include <iostream>
#include <queue>

#include "tools_tree.cpp"


using namespace std;


// https://leetcode-cn.com/problems/path-sum/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return bfs(root, sum);
        // return dfs(root, sum);
    }


    bool dfs(TreeNode* node, int sum) {
        if (!node) {
            return false;
        }
        if (!node->left && !node->right) {
            return sum == node->val;
        }
        return dfs(node->left, sum - node->val) || dfs(node->right, sum - node->val);
    }


    bool bfs(TreeNode* node, int sum) {
        if (!node) {
            return false;
        }
        stack<pair<TreeNode*, int>> nodeStack;   /// 记录当前节点，与到当前结点的和
        nodeStack.push(pair<TreeNode*, int>(node, node->val));

        while (!nodeStack.empty()) {
            pair<TreeNode*, int> node = nodeStack.top(); nodeStack.pop();
            TreeNode* left = node.first->left, *right = node.first->right;
            // 叶子节点并且值相等
            if (!left && !right  && node.second == sum ) {
                return true;
            }

            if (right) {
                nodeStack.push(pair<TreeNode*, int>(right, node.second + right->val));
            }
            if (left) {
                nodeStack.push(pair<TreeNode*, int>(left, node.second  + left->val));
            }
        }
        return false;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    // std::vector<int> Data{5, 4, 8, 11, 13, 4, 7, 2, null, 1};
    std::vector<int> Data{5,4,8,11,null,13,4,7,2,null,null,null,1};
    TreeNode* Root = NULL;
    Root = createBinaryTree(Data);
    levelOrder(Root);
    ::cout << boolalpha << Solution().hasPathSum(Root, 22);
    // copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
