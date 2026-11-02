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
    int tot;
    void good(TreeNode* root, int l_max) {
        if(!root)
            return;
        if(root->val >= l_max) {
            tot += 1;
            l_max = root->val;
        }
        good(root->left, l_max);
        good(root->right, l_max);
        
    }
    int goodNodes(TreeNode* root) {
        tot = 0;
        good(root, INT_MIN); 
        return tot;
    }
};
