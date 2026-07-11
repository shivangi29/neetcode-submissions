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
    bool ret;
    int height(TreeNode* root) {
        if(!root) return 0;
        int h1 = height(root->left);
        int h2 = height(root->right);
        //cout<<root->val<<" h1 "<<h1<<" h2 "<<h2<<endl;
        if(h1-h2 > 1 || h2-h1 > 1) ret = false;
        return 1 + max(h1,h2); 
    }
    bool isBalanced(TreeNode* root) {
        ret = true;
        height(root);
        return ret;    
    }
};
