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
    ListNode* add(ListNode* l1, ListNode* l2, int c) {
        ListNode *head1 = NULL, *head2 = NULL, *newNode = NULL;
        if(l1 || l2) {
            int a = 0, b = 0;
            if(l2) {
                b = l2->val;
                head2 = l2->next;
            }
            if(l1) {
                a = l1->val;    
                head1 = l1->next;
            }
            int s = (a+b+c)%10;
            c = (a+b+c)/10;
            newNode = new ListNode(s);

            newNode->next = add(head1, head2, c);
        } else if(c)
            return new ListNode(c);
        return newNode;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
     
        return add(l1, l2, 0);
    }
};
