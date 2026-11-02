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
    int good(TreeNode* root, int l_max) {
        if(!root)
            return 0;
        int tot = 0;
        if(root->val >= l_max) {
            tot = 1;
            l_max = root->val;
        }
        tot += good(root->left, l_max);
        tot += good(root->right, l_max);
        
        return tot;
    }
    int goodNodes(TreeNode* root) {
        return good(root, INT_MIN); 
    }
};
