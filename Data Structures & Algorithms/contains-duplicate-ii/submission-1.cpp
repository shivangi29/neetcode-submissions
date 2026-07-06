class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k == 0) return false;
        int n = nums.size();
        for(int i = 0 ; i < n; i++) {
            for(int j = 1; j<=k && i+j < n; j++)
                if(nums[i] == nums[i+j])
                    return true;
        }
        return false;
    }
};