#include <unordered_map>

class LRUCache {
public:
    struct Node {
        int val, key;
        Node *prev, *next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    
    // Permanent boundary anchors to prevent Null Pointer Exceptions
    Node *head, *tail;
    std::unordered_map<int, Node*> hash;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // Helper: Safely isolates a node from its current neighbors
    void removeNode(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;
    }

    // Helper: Always inserts right after the dummy head (Most Recently Used)
    void insertAtHead(Node* node) {
        Node* nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }

    int get(int key) {
        if (hash.find(key) == hash.end()) {
            return -1;
        }
        Node* node = hash[key];
        removeNode(node);     // Take it out of its current spot
        insertAtHead(node);   // Move it to the front
        return node->val;
    }
    
    void put(int key, int value) {
        if (hash.find(key) != hash.end()) {
            // Key exists: Update value and shift to head
            Node* node = hash[key];
            node->val = value;
            removeNode(node);
            insertAtHead(node);
        } else {
            // Key is new: Check capacity limits
            if (hash.size() == cap) {
                Node* lruNode = tail->prev; // The node right before dummy tail
                removeNode(lruNode);
                hash.erase(lruNode->key);   // Clean up the hash map
                delete lruNode;             // Clear heap memory
            }
            
            // Add the new item
            Node* newNode = new Node(key, value);
            hash[key] = newNode;
            insertAtHead(newNode);
        }
    }
    
    // Optional Destructor to prevent memory leaks during testing
    ~LRUCache() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};
