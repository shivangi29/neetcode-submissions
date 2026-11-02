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
    int ans, count;
    void kth(TreeNode* root, int k) {
        if(!root)
            return;
        kth(root->left, k);
        count++;
        if(k == count) {
            ans = root->val;
            return;
        }
        kth(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        kth(root, k);
        return ans;
    }
};
