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
/*int m = n;
        ListNode *s = head, *p = head, *prev = NULL;
        while(--m) {
            s = s->next;
        }
        while(s->next) {
            prev = p;
            p = p->next;
            s = s->next;
        }

        if(p == head) {
            head = head->next;
        } else {
            prev->next = p->next;
        }
        return head;*/
class Solution {
public:
    int m;
    ListNode* remove(ListNode* head) {
      //  cout<<n<<endl;
        if(!head || head->next == NULL)
            return head;
        ListNode* tmp = remove(head->next);
        if(--m == 0) {
            cout<<"come here";
            head->next = tmp->next;
        }
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        cout<<n<<endl;
        m=n;
        if(!head || head->next == NULL)
          return NULL;
        ListNode* tmp = remove(head);
        if(m==1)
            return head->next;
        return tmp; 
    }
};
