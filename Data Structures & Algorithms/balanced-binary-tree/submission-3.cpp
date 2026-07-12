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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        unordered_map<TreeNode*, int> mp;
        mp[NULL] = 0;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* curr = stk.top();
            if(curr->left && mp.find(curr->left) == mp.end()) {
                stk.push(curr->left);
            } else if(curr->right && mp.find(curr->right) == mp.end()) {
                stk.push(curr->right);
            } else {
                stk.pop();
                if(mp.find(curr->left) != mp.end() && mp.find(curr->right) != mp.end()) {
                    int h1 = mp[curr->left];
                    int h2 = mp[curr->right];
                    //cout<<h1<<" "<<h2<<endl;
                    if(h1-h2 >1 || h2-h1>1) return false;
                }
                mp[curr] = 1 + max(mp[curr->left], mp[curr->right]);
            }
        }
        return true;    
    }
};
