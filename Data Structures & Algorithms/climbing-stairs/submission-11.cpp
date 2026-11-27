class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
            return n;
        int a = 1, b = 2;
        int sum;
        for(int i = 3; i <=n ; i++){
            sum = a+b;
            a = b;
            b = sum;
        }
        return sum;
    }
};
