/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> hash;
    /*Node* copy(Node* head) {
        Node *newNode = NULL, *newRandom = NULL;
        if(hash.find(head) != hash.end()) {
            newNode = hash[head];
        } else {
            newNode = new Node(head->val);
            hash[head] = newNode;
        
        }
        if(hash.find(head->random) != hash.end()) {
                newRandom = hash[head->random];
            } else {
                newRandom = new Node(head->random->val);
            }
            newNode->random = newRandom;
            hash[head->random] = newRandom; 
            if(prev) {
                prev->next = newNode;
            }
    }*/
    Node* copyRandomList(Node* head) {
        Node *newNode = NULL, *newHead = NULL, *newRandom = NULL;
        Node* prev = NULL;
        hash[NULL] = NULL;
        while(head != NULL) {
            if(hash.find(head) != hash.end()) {
                newNode = hash[head];
            } else {
                newNode = new Node(head->val);
                hash[head] = newNode;
            
            }
            if(hash.find(head->random) != hash.end()) {
                newRandom = hash[head->random];
            } else {
                newRandom = new Node(head->random->val);
                hash[head->random] = newRandom; 
            }
            newNode->random = newRandom;
            if(prev) {
                prev->next = newNode;
            }
            if(newHead == NULL) {
                newHead = newNode;
            }
            prev = newNode;
            head = head->next;
        }
        return newHead;

    }
};
