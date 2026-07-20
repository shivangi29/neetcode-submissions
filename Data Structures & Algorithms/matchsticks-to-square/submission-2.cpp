class Solution {
public:
    bool makeSq(vector<int>& nums, int len, int sum, int tot, int n, vector<bool>& vis) {
        if(len == 0) {
            tot++;
            len = sum;
         }
        if(tot == 4 && n == 0) {
            return true;
        }
        for(int i = 0 ; i < nums.size(); i++) {
            if(nums[i]<=len && !vis[i]) {
                vis[i] = true;
                if(makeSq(nums, len-nums[i], sum, tot, n-1, vis))
                    return true;
                vis[i] = false;                
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        vector<bool> vis(n, false);

        int sum = 0;
        for(int num : matchsticks)
            sum += num;
        
        if(sum%4) return false;
        
        int len = sum/4;
        
        for(int num : matchsticks) {
            if(num > len)
                return false;
        }
        //sort(matchsticks.begin(), matchsticks.end());
        return makeSq(matchsticks, len, len, 0, n, vis); 
    }
};