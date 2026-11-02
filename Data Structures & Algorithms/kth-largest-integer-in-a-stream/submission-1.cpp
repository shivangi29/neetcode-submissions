class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> heap;
    int max;
    KthLargest(int k, vector<int>& nums) {
        max = k;
        for(int num : nums) {
            heap.push(num);
            if(heap.size()>k)
                heap.pop();
        }
    }
    
    int add(int val) {
        heap.push(val);
        if(heap.size()>max)
            heap.pop();
        return heap.top();
    }
};
