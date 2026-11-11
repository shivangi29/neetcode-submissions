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
    int ans;
    int maxPath(TreeNode* root) {
        if(!root) return 0;
        int par = root->val;
        int left = maxPath(root->left);
        int right = maxPath(root->right);
        //cout<<"par "<<par<<" left "<<left<<" right "<<right<<endl;
        ans = max(ans, max(par, par+left+right));
        ans = max(ans, max(par+left, par+right));
        //cout<<"ans "<<ans<<endl;
        return max(max(par+left, par+right), par);
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        maxPath(root);
        return ans;
    }
};
