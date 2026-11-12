class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        
        while(set.count(n)==0) {
            set.insert(n);
            int s = 0;
            while(n) {
                int d = n%10;
                s += d*d;
                n = n/10;
            }
            if(s == 1)
                return true;
            n = s;
        }
        return false;
    }
};
