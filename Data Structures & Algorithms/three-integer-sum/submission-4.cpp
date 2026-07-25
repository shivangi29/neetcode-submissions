class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size();
        for(int i = 0 ; i < n - 2 ; i++) {
            int target = 0 - nums[i];
            set<int> hash;
            for(int j = i+1; j < n;j++) {
                if(hash.count(target - nums[j])) {
                    vector<int> tmp({nums[i],nums[j],target - nums[j]});
                    sort(tmp.begin(), tmp.end());
                    ans.insert(tmp);
                } else
                    hash.insert(nums[j]);
            }
        }
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};
