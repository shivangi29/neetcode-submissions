class MyCircularQueue {
public:
    vector<int> cq;
    int head, tail, sz, cap;
    MyCircularQueue(int k) {
        cq.resize(k);
        head = -1;
        tail = -1;
        sz = 0;
        cap = k;
    }
    
    bool enQueue(int value) {
        if(sz < cap) {
            if(head == -1)
                head = 0;
            tail = (tail + 1)%cap;
            cq[tail] = value;
            sz++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(head == -1)
            return false;
        if(head == tail) {
            head = -1;
            tail = -1;
        } else {
            head = (head+1)%cap;
        }
        sz--;
        return true;
    }
    
    int Front() {
        if(head == -1)
            return -1;
        return cq[head];
    }
    
    int Rear() {
        if(tail == -1)
            return -1;
        return cq[tail];
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