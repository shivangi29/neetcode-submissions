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
    struct comp {
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        ListNode *ans = new ListNode(0), *tail;
        for(auto head : lists)
            if(head)
                pq.push(head);
        tail = ans;
        while(!pq.empty()) {
            ListNode *nextNode = pq.top();
            pq.pop();
            tail->next = nextNode;
            tail = nextNode;
            if(nextNode->next)
                pq.push(nextNode->next);
        }
        return ans->next;
    }
};
