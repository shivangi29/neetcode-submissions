/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int g_max;
    int height(TreeNode* root) {
        if(!root) return 0;
        int h1 = height(root->left);
        int h2 = height(root->right);
        g_max = max(g_max, h1+h2);
        //cout<<h1<<h2<<endl;
        return 1+ max(h1,h2);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        g_max = 0;
        height(root);
        return g_max;
    }
};
