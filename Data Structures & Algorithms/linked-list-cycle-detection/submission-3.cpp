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
    bool hasCycle(ListNode* head) {
        ListNode *f = head, *s =head;//1
        while(s && s->next && f && f->next) {
            s = s->next;//2
            f = f->next->next;//1
            if(s==f) return true;
        }
        return false;
    }
};
