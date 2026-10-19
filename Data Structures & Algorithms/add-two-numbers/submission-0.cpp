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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *sum = l1, *prev = NULL;
        int c = 0;
        while(l1 || l2) {
            int a = 0, b = 0;
            if(!l1) {
                prev->next = l2;
                l1 = l2;
                l2 = NULL;
            }
            if(l2) {
                b = l2->val;
                l2 = l2->next;
            }
            if(l1) {
                prev = l1;
                a = l1->val;
            }
            l1->val = (a+b+c)%10;
            c = (a+b+c)/10;
            l1 = l1->next;
        }
        if(c && prev)
            prev->next = new ListNode(c);

        return sum;
        // 1
        // 9 --> 9 --> 9 -> 9
    }
};
