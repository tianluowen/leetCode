// date: 2020-03-29
// desc: 001_minimum-depth-of-binary-tree/

#include <iostream>

using namespace std;

struct TreeNode 
{
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    int run(TreeNode *root) {
        // 根节点为空
        if (root == NULL)
            return 0;
        // 左右节点都为空
        if (root->left == NULL && root->right == NULL)
             return 1;
        // 左节点为空
        if (root->left == NULL && root->right != NULL)
            return run(root->right) + 1;
        // 右节点为空
        if (root->right == NULL && root->left != NULL)
            return run(root->left) + 1;
        
        // 左右节点都不为空 返回左右节点小的那个
        int l = run(root->left);
        int r = run(root->right);
        return l < r ? l + 1 : r + 1;
    }
};



          

int main(void)
{
    Solution s;
    TreeNode* root = new TreeNode();
    root->left = new TreeNode();
    root->right = new TreeNode();
    root->left->right = new TreeNode();
    root->left->left = NULL;
    root->right->left = NULL;
    root->right->right = NULL;

    cout << "测试树的形状依次为如下，其中 * 表示该位置有节点" << endl;
    cout << "   *    \n";
    cout << " *   *  \n";
    cout << "  *     \n";

    cout << endl << "该二叉树的最小深度 = " << s.run(root) << endl;

    delete root->left->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
