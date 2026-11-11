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
    int startRob(TreeNode* root) {
        if(!root) return 0;
        int res = root->val;
        if(root->left)
            res += startRob(root->left->left) + startRob(root->left->right);
        if(root->right)
            res += startRob(root->right->left) + startRob(root->right->right);
        
        return max(res, startRob(root->left) + startRob(root->right));
     
    }
    unordered_map<TreeNode*, int> hash;

    int add(TreeNode* root) {
        if(hash.find(root) != hash.end())
            return hash[root];
        int res = root->val;
        if(root->left)
            res += add(root->left->left) + add(root->left->right);
        if(root->right)
            res += add(root->right->left) + add(root->right->right);
        hash[root] = max(res, add(root->left) + add(root->right));
        return hash[root];
    }
    int rob(TreeNode* root) {
        hash[nullptr] = 0;
        return add(root);
    }
};