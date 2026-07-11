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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        stack<TreeNode*> stk;

        while(curr || !stk.empty()) {
            while(curr) {
                ans.push_back(curr->val);
                stk.push(curr);
                curr = curr->right;
            }
            curr = stk.top();
            stk.pop();
            curr = curr->left;
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};