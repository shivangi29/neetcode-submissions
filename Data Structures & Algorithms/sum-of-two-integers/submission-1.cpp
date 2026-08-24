class Solution {
public:
    int getSum(int a, int b) {
        unsigned int ua = a;
        unsigned int ub = b;
        int c = 0;
        int pos = 0, res = 0;
        while(ua || ub) {
            int a1 = ua&1;
            int b1 = ub&1;
            int last = a1 ^ b1 ^ c;;
            c = (a1 & b1) | (b1 & c) | (a1 & c);
            res = res|(last<<pos);
            pos++;
            ua >>= 1; ub >>= 1;
        }
        // 4. If there is a leftover carry at the very end, place it
        if (c && pos < 32) {
            res = res | (c << pos);
        }
        return res;
    }
};
