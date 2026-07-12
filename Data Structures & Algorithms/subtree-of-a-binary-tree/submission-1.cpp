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
    bool isEqual(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(p && q && p->val == q->val) 
            return isEqual(p->left, q->left) && isEqual(p->right, q->right);
        else
            return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(isEqual(root,subRoot)) 
            return true;
        if(root->left && isSubtree(root->left,subRoot))
            return true;
        if(root->right && isSubtree(root->right,subRoot))
            return true;
        return false;
    }
};
