class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        int res = 0;
        while(l <= r) {
            int m = l + (r-l)/2;
            long long num = (long long)m*m;
            if(num == x) {
                return m;
            } else if( x < num) {
                r = m - 1;
            } else {
                res = m;
                l = m + 1;
            }
        }

        return res;
    }
};