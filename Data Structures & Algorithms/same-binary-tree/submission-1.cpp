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
    bool check (TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if((p && !q) || (q && !p)) return false;
        return p->val == q->val;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p); q2.push(q);
        while(!q1.empty() || !q2.empty()) {
            p = q1.front();    q = q2.front();
            q1.pop(); q2.pop();
            if(!check(p,q)) return false;
            if(p){
                q1.push(p->left);
                q1.push(p->right);
            }
            if(q){
                q2.push(q->left);
                q2.push(q->right);
            }
        }
        return true;
    }
};
