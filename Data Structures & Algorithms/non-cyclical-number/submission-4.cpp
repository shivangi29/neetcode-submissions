class Solution {
public:
    int sqSum(int n) {
        int s = 0;
        while(n) {
            int d = n%10;
            s += d*d;
            n = n/10;
        }
        return s;
    }
    bool isHappy(int n) {
        int slow = n, fast = sqSum(n);
        while(slow!=fast) {
            slow = sqSum(slow);
            fast = sqSum(sqSum(fast));
        }
        return fast==1;
    }
};
