class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c_5 = 0, c_10 = 0, c_20 = 0;
        for(int money : bills) {
            if(money == 5)
                c_5++;
            else if(money == 10) {
                if(c_5 == 0)
                    return false;
                c_5--; c_10++;
            } else if(money == 20) {
                if(c_10 && c_5) {
                    c_10--; c_5--;
                } else if(c_5 >= 3) {
                    c_5 -= 3;
                } else
                    return false;
            }
        }
        return true;
    }
};