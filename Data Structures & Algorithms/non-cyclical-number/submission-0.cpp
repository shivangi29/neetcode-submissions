class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(1) {
            if(n == 1)
                return true;
            int s = 0;
            while(n) {
                int d = n%10;
                s += d*d;
                n = n/10;
            }
            if(set.count(s))
                return false;
            set.insert(s);
            n = s;
        }
        return false;
    }
};
