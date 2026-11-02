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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*, int>> que;
        if(root)
            que.push({root, INT_MIN});
        int tot = 0;
        while(!que.empty()) {
            auto top = que.front();
            que.pop();
            TreeNode* curr = top.first;
            int l_max = top.second;
            if(curr->val >= l_max){
                l_max = curr->val;
                tot++;
            }
            if(curr->left) {
                que.push({curr->left, l_max});
            }
            if(curr->right) {
                que.push({curr->right, l_max});
            }
        }
        return tot;
    }
};
