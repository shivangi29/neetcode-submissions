class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        int n = nums.size();
        for(int i = 0 ; i < n - 2 ; i++) {
            int target = 0 - nums[i];
            for(int j = i+1; j < n-1;j++) {
                for (int k = j+1; k < n; k++) {
                    int tmp = nums[j] + nums[k];
                    if(tmp == target) {
                        vector<int> cur({nums[i], nums[j], nums[k]});
                        sort(cur.begin(), cur.end());
                        res.insert(cur);
                    }
                }
            }
        }
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};
