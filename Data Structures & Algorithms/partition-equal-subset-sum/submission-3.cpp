class Solution {
public:
    int n;
    int ret = false;
    vector<vector<int>> memo;
    bool tryPart(vector<int>& nums, int i, int tar) {
        if(tar<0) return false;
        if(i < 0 ) {
            if(tar == 0) {
                return true;
            }
            return false;
        }
        if(memo[i][tar] != -1)
            return memo[i][tar];

        return memo[i][tar] = tryPart(nums, i-1, tar) 
                || tryPart(nums, i-1, tar-nums[i]);
        
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int tot = 0;
        for(int i : nums)
            tot+=i;
        if(tot%2) return false;

        memo.assign(n, vector<int>(tot/2+1, -1));

        return tryPart(nums, n-1, tot/2);
    }
};
