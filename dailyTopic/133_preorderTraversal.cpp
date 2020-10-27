#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stack>

#include "tools_tree.cpp"



using namespace std;


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // return preorderTraversal_0(root);
        // return preorderTraversal_1(root);
        // return preorderTraversal_1_1(root);
        return morrisInorderTraverse(root);
    }

    // https://leetcode-cn.com/problems/binary-tree-preorder-traversal/solution/leetcodesuan-fa-xiu-lian-dong-hua-yan-shi-xbian-2/
    // Morris的整体思路就是将 以某个根结点开始，找到它左子树的最右侧节点之后与这个根结点进行连接,
    // 连接之后,cur 这个指针是可以完整的从一个节点顺着下一个节点遍历，将整棵树遍历完毕
    vector<int> morrisInorderTraverse(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        TreeNode* cur1 = root;          //遍历树的指针变量
        TreeNode* cur2 = nullptr;       //当前子树的最右节点
        while (nullptr !=  cur1) {
            cur2 = cur1->left;
            if (nullptr != cur2) {      // 当前节点的左子节点不为空
                //找到当前左子树的最右侧节点，且这个节点应该在指向根结点之前，否则整个节点又回到了根结点。
                while (cur2->right != nullptr && cur2->right != cur1) {
                    cur2 = cur2->right;
                }
                //这个时候如果最右侧这个节点的右指针没有指向根结点，创建连接然后往下一个左子树的根结点进行连接操作。
                if (nullptr == cur2->right) {
                    res.emplace_back(cur1->val);
                    cur2->right = cur1;
                    cur1 = cur1->left;
                    continue;
                } else {
                    //当左子树的最右侧节点有指向根结点，此时说明我们已经回到了根结点并重复了之前的操作，同时在回到根结点的时候我们应该已经处理完 左子树的最右侧节点 了，把路断开。
                    cur2->right = nullptr;
                }
            } else {    // 当前节点的左子节点为空
                res.emplace_back(cur1->val);
            }

            cur1 = cur1->right;  //一直往右边走，参考图
        }
        return res;
    }


    vector<int> preorderTraversal_1(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        // 初始化栈，并将根节点入栈
        stack<TreeNode*> stk;
        TreeNode* node;
        stk.emplace(root);
        while (!stk.empty()) {
            //弹出栈顶元素 node
            node = stk.top();
            stk.pop();
            if (node != nullptr) {
                res.emplace_back(node->val);
                if (node->right != nullptr) {
                    stk.emplace(node->right);   //右子树入栈
                }
                if (node->left != nullptr) {
                    stk.emplace(node->left);   //左子树入栈
                }
            }
        }
        return res;
    }


    vector<int> preorderTraversal_1_1(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while (!stk.empty() || node != nullptr) {
            //将根节点 node 和所有的左孩子入栈并加入结果中
            while (node != nullptr) {
                res.emplace_back(node->val);
                stk.emplace(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            node = node->right;
        }
        return res;
    }


    // 递归版本
    vector<int> preorderTraversal_0(TreeNode* root) {
        vector<int> res;
        PreTraversal(root, res);
        // copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
        return res;
    }


    void PreTraversal(TreeNode* root, vector<int>& arr) {
        if (root) {
            arr.push_back(root->val);
            PreTraversal(root->left, arr);
            PreTraversal(root->right, arr);
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    std::vector<int> Data{1,null,2,3};
    TreeNode* Root = NULL;
    Root = createBinaryTree(Data);
    vector<int>res = Solution().preorderTraversal(Root);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
