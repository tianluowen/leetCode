// date: 2020-04-22
// desc: 给定一个二叉树，返回它的 后序 遍历

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> list;
        stack<TreeNode> sta;
        TreeNode tempNode(0);
        
        // 为空 返回空
        if (root == nullptr)
            return list;
        
        // 将根结点 入栈，依次取出，当某个结点无子节点时，将数据入 列表 否则 入栈
        sta.push(*root);
        while (!sta.empty())
        {
            tempNode = sta.top();
            sta.pop();
            list.insert(list.begin(), tempNode.val);
            
            // 注意插入 list 开始的位置 
            if (tempNode.left != nullptr)
            {
                sta.push(*tempNode.left);
            }
            if (tempNode.right != nullptr)
            {
                sta.push(*tempNode.right);
            }
        }
       
        return list;
    }
};            
        

int main(void)
{
    Solution s;
    vector<int> v;
    
    TreeNode* head = new TreeNode(2);
    head->left = new TreeNode(4);
    head->right = new TreeNode(3);
    head->left->right = new TreeNode(1);
    head->right->left = new TreeNode(6);

    cout << "原来的树: " << endl;
    cout << "    2" << endl;
    cout << "4       3" << endl;;
    cout << "  1  6" << endl;

    v = s.postorderTraversal(head);

    cout << "\n后序输出结果：\n";
    cout << "[ ";
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << " ]" << endl;

    delete head->left->right;
    delete head->right->left;
    delete head->left;
    delete head->right;
    delete head;

    return 0;
}
