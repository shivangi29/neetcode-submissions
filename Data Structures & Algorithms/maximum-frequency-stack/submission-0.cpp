class FreqStack {
public:
    map<int, vector<int>, greater<int>> hash;
    map<int, int> count;
    FreqStack() {
        
    }
    
    void push(int val) {
        int rep = count[val];
        hash[rep+1].push_back(val);
        count[val] += 1;
    }
    
    int pop() {
        auto first_entry = hash.begin();
        int val = first_entry->second.back();
        first_entry->second.pop_back();
        count[val] -= 1;
        if(count[val] == 0)
            count.erase(val);
        if(first_entry->second.size() == 0)
            hash.erase(first_entry);
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */