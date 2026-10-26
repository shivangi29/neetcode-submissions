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
ListNode* rev(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* newHead = rev(head->next);
        
        head->next->next = head;
        head->next = nullptr;
        
        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || !head ||!head->next)
            return head;
        int count = k;
        ListNode *ans = NULL;
        ListNode *prev = NULL, *curr = head;
        ListNode *thead = head, *lastHead = NULL, *save=NULL;
        while(curr) {
            while(curr && --count)
                curr = curr->next;
            if(count==0 && curr) {
                save = curr->next;
                curr->next = NULL;
                if(!ans) ans = curr;
                rev(thead);

                if(lastHead)
                    lastHead->next = curr;
                
                curr = save;
                lastHead = thead;
                thead = save;
                count = k;
            }
        }
        if(count && lastHead)
            lastHead->next = thead;
        return ans;
    }
};
