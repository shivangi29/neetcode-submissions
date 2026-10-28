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
    vector<int> ans;       
    void rightView(TreeNode* root, int level) {
        if(!root) return;
        if(ans.size() == level)
            ans.push_back(0);
        ans[level] = root->val;
        rightView(root->left, level+1);
        rightView(root->right, level+1);
    } 
    vector<int> rightSideView(TreeNode* root) {
        rightView(root, 0);    
        return ans;
    }
};
