class Solution {
public:
    void twosums(set<vector<int>>& hash, vector<int>& nums, int i) {
        int l = i+1, r = nums.size()-1;
        int target = 0 - nums[i];
        while(l < r) {
            if(nums[l]+nums[r] == target) {
                vector<int> tmp = {nums[i], nums[l], nums[r]};
                sort(tmp.begin(), tmp.end());
                hash.insert(tmp);
                l++; r--;
            } else if(nums[l]+nums[r] < target) {
                l++;
            } else {
                r--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> hash;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i <= n-3; i++) {
            twosums(hash, nums, i);
        }
        vector<vector<int>> ans(hash.begin(), hash.end());
        return ans;
    }
};
