/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *fast = head, *slow=head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *l1 = head;
        
        ListNode *prev = NULL, *curr = slow;
        while(curr) {
            ListNode* save = curr->next;
            curr->next = prev;
            prev = curr;
            curr = save;
        } 
        ListNode *l2 = prev;

        int ans = 0;
        while(l2 != nullptr) {
            ans = max(ans, l1->val+l2->val);
            l1 = l1->next; l2 = l2->next;
        } 
        return ans;
    }
};