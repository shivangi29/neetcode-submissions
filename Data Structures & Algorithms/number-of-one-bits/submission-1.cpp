class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = n, count = 0;
        while(num) {
            num = (num-1)&num;
            count++;
        }
        return count;
    }
};
