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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        stack<TreeNode*> stk;
        while(curr || !stk.empty()) {
            if(!curr) {
                curr = stk.top();
                stk.pop();
            }
            ans.push_back(curr->val);
            if(curr->right)
                stk.push(curr->right);
            curr = curr->left;

        }
        return ans;
    }
};