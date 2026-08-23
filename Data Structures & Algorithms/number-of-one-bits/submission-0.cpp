class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = n, count = 0;
        while(num) {
            if(num &1) count++;
            num = num>>1;
        }
        return count;
    }
};
