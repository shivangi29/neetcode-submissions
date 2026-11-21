class Solution {
public:
    void twosums(vector<vector<int>>& ans, vector<int>& nums, int i) {
        int l = i+1, r = nums.size()-1;
        int target = 0 - nums[i];

        while(l < r) {
            if(l > i+1 && nums[l] == nums[l-1]) {
                l++;
                continue;
            }
            if(r < nums.size()-1 && nums[r] == nums[r+1]) {
                r--;
            }
            if(l>=r)
                break;
            if(nums[l]+nums[r] == target) {
                ans.push_back({nums[i], nums[l], nums[r]});
                l++; r--;
            } else if(nums[l]+nums[r] < target) {
                l++;
            } else {
                r--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i <= n-3; i++) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            twosums(ans, nums, i);
        }
        return ans;
    }
};
