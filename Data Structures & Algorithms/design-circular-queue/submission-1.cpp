class MyCircularQueue {
public:
    struct Node {
        int val;
        Node* next;
        Node(int v): val(v), next(nullptr) {}
    };
    Node *head, *tail;
    int sz, cap;
    MyCircularQueue(int k) {
        head = nullptr;
        tail = nullptr;
        sz = 0;
        cap = k;
    }
    
    bool enQueue(int value) {
        if(sz < cap) {
            Node *newNode = new Node(value);
            if(head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            sz++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(head == NULL)
            return false;
        if(head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
        } else {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
        sz--;
        return true;
    }
    
    int Front() {
        if(head == NULL)
            return -1;
        return head->val;
    }
    
    int Rear() {
        if(tail == NULL)
            return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return sz==0;
    }
    
    bool isFull() {
        return sz==cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */