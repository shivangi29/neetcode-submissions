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

    struct ele {
        TreeNode* curr;
        int min, max;
    };
    bool isValidBST(TreeNode* root) {
        queue<ele> que;
        if(root)
            que.push({root, INT_MIN, INT_MAX});
        while(!que.empty()) {
            auto top = que.front();
            que.pop();
            TreeNode* curr = top.curr;
            int min = top.min, max = top.max;
            if(curr->val <= min || curr->val >= max)
                return false;
            if(curr->left)
                que.push({curr->left,min,curr->val});
            
            if(curr->right)
                que.push({curr->right,curr->val, max});
        }

        return true; 
    }
};
