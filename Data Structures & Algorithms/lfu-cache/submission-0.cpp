#include <unordered_map>
#include <iostream>

using namespace std;

class LFUCache {
public:
    struct Node {
        int key, val, freq;
        Node *next, *prev;
        Node(int key, int val): key(key), val(val), freq(1), prev(nullptr), next(nullptr){}
    };
    
    struct arr {
        Node *head, *tail;
        int size;
    };
    
    unordered_map<int, Node*> nodeMap;
    unordered_map<int, arr> listMap;
    int sz = 0, cap, lfuCount;

    LFUCache(int capacity) {
        cap = capacity;
        lfuCount = 0;
    }
    
    int get(int key) {
        if(nodeMap.find(key) != nodeMap.end()) {
            Node *node = nodeMap[key];
            int freq = node->freq;
            node->freq = freq + 1;
            removeNode(freq, node);
            insert(freq + 1, node);
            return node->val;
        }
        return -1;
    }
    
    void removeNode(int freq, Node* lruNode) {
        listMap[freq].size--;
        Node *prev = lruNode->prev;
        Node *next = lruNode->next;
        prev->next = next;
        next->prev = prev;
        
        // FIX 1: If the minimum frequency list becomes empty, advance lfuCount by 1
        if(listMap[freq].size == 0) {
            if(freq == lfuCount)
                lfuCount++;
        }
    }
    
    void insert(int freq, Node* newNode) {
        if(listMap.find(freq) == listMap.end()) {
            Node *head = new Node(0, 0);
            Node *tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head; 
            arr myArr = {head, tail, 0};
            listMap[freq] = myArr;
        }
        Node *head = listMap[freq].head;
        Node *tmp = head->next;
        listMap[freq].size++;
        
        tmp->prev = newNode; 
        newNode->next = tmp;
        newNode->prev = head;
        head->next = newNode;
    }
    
    void put(int key, int value) {
        if (cap <= 0) return; // FIX 2: Safeguard against zero or negative capacity

        if(nodeMap.find(key) != nodeMap.end()) {
            Node *node = nodeMap[key];
            node->val = value; // FIX 3: Update the actual value of the key!
            int freq = node->freq;
            node->freq = freq + 1;
            removeNode(freq, node);
            insert(freq + 1, node);
        } else {
            Node *newNode = new Node(key, value);
            if(sz == cap) {
                Node *tail = listMap[lfuCount].tail;
                Node *lruNode = tail->prev;
                nodeMap.erase(lruNode->key);
                removeNode(lfuCount, lruNode);
                delete lruNode;
            } else {
                sz++;
            }
            lfuCount = 1; // New nodes always start with a frequency of 1
            nodeMap[key] = newNode; // Don't forget to register the new node in nodeMap!
            insert(1, newNode);
        }
    }
};
