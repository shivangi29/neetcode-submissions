class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> vis(nums.size(), 0);
        if(nums.size() <= 1)
            return true;
        if(nums[0] == 0)
            return false;
        vis[0] = true;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0 || vis[i] == false)
                continue;
            for(int j = i; j <= nums[i]+i; j++) {
                vis[j] = true;
            }
        }
        return vis[nums.size()-1];
    }
};
