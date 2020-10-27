#include <vector>
#include <queue>
#include <iostream>


#define null 65535


// Definition for a binary tree node.
struct BinaryTreeNode {
    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode() : val(0), left(nullptr), right(nullptr) {}
    BinaryTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    BinaryTreeNode(int x, BinaryTreeNode *left, BinaryTreeNode *right) : val(x), left(left), right(right) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};




TreeNode* createBinaryTree(std::vector<int> arr)
{
    TreeNode *root = nullptr, *tmp;
    if (arr[0] == null) {
        return root;
    }
    std::vector<TreeNode*> NodesNow;     //用于存储当前层的结点
    std::vector<TreeNode*> FatherNodes;  //用于存储上一层的结点
    root = new TreeNode(arr[0]);
    FatherNodes.push_back(root);
    int index = 1;
    int MaxNum = FatherNodes.size()*2;  //用于存储每一层可以存储的最大结点个数，应该是上一层非空结点的2倍
    int SaveNum = 0;                    //用于记录当前层已经存储了多少结点
    bool LRFlag = false;                //用于记录下一个上上层结点的左孩子还是右孩子
    while (index < arr.size()) {
        if (arr[index] == null && SaveNum < MaxNum) {
            SaveNum++;
            index++;
            if (index == arr.size()) break;
            if (LRFlag) LRFlag = false;
            else LRFlag = true;
            continue;
        }
        if (SaveNum < MaxNum) {
            tmp = new TreeNode(arr[index]);
            NodesNow.push_back(tmp);
            if (LRFlag) {
                FatherNodes[SaveNum / 2]->right = tmp;  //添加到右子树中
                LRFlag = false;
            } else {
                FatherNodes[SaveNum / 2]->left = tmp;  //添加到左子树中
                LRFlag = true;
            }
            SaveNum++;
            index++;
        } else {            //当前层节点数已经满了，清空状态
            SaveNum = 0;
            MaxNum = NodesNow.size() * 2;
            LRFlag = false;
            FatherNodes.clear();
            for (int i = 0; i < NodesNow.size(); i++) {
                FatherNodes.push_back(NodesNow[i]);
            }
            NodesNow.clear();
        }
    }
    return root;
}



///先序遍历输出
void PreTraversal(TreeNode *p) {
    if (p != NULL) {
        std::cout << p->val << " ";
        PreTraversal(p->left);
        PreTraversal(p->right);
    }
}


void levelOrder(TreeNode* root) {
    std::queue <TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto node = q.front(); q.pop();
        std::cout << node->val << " ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}


std::vector<std::vector<int>> levelOrder_1(TreeNode* root) {
    std::vector <std::vector <int>> ret;
    if (!root) {
        return ret;
    }

    std::queue <TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int currentLevelSize = q.size();
        ret.push_back(std::vector <int> ());
        for (int i = 1; i <= currentLevelSize; ++i) {
            auto node = q.front(); q.pop();
            ret.back().push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return ret;
}



// void pre(TreeNode *root, int depth) {
//         if (!root) return ;
//         if (depth >= ans.size())
//             ans.push_back(vector<int> {});
//         ans[depth].push_back(root->val);
//         pre(root->left, depth + 1, ans);
//         pre(root->right, depth + 1, ans);
//     }


int main(int argc, char const *argv[])
{
    /* code */
    std::cout << 0/2 << std::endl;
    std::vector<int> Data{3, 9, 20, null, null, 15, 7};
    TreeNode* root = createBinaryTree(Data);
    PreTraversal(root);

    return 0;
}
