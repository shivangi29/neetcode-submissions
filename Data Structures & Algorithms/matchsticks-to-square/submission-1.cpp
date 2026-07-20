class Solution {
public:
    unordered_map<int,int> hash;
    bool makeSq(vector<int>& nums, int len, int sum, int tot, int n) {
        if(len == 0) {
            tot++;
            len = sum;
         }
        if(tot == 4 && n == 0) {
            return true;
        }
        for(auto &[a,b] : hash ) {
            if(a<=len && b) {
                b--;
                if(makeSq(nums, len-a, sum, tot, n-1))
                    return true;
                b++;                
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        hash.clear();
        int sum = 0;
        for(int num : matchsticks)
            sum += num;
        if(sum%4) return false;
        int len = sum/4;
        for(int num : matchsticks) {
            hash[num]++;
            if(num > len)
                return false;
        }
        sort(matchsticks.begin(), matchsticks.end());
        return makeSq(matchsticks, len, len, 0, matchsticks.size()); 
    }
};