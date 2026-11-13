class Solution {
public:
    unordered_map<int, double> hash;
    double findPow(double x, int n) {
        if(hash.find(n) != hash.end())
            return hash[n];
        hash[n/2] = findPow(x,  n/2);
        if(n & 1) {
            return x * hash[n/2] * hash[n/2];
        } 
        return hash[n/2] * hash[n/2];
    }
    double myPow(double x, int n) {
        if(x == -1) {
            if(n&1)
                return -1;
            else return 1;
        }
        if(x == 0.0)
            return 0.0;
        if(x == 1.0) return 1.0;

        hash[1] = x;
        hash[0] = 1.0;
        double ans = findPow(x, abs(n));
        if(n<0)
            return 1.0/ans;
        return ans;
    }
};
