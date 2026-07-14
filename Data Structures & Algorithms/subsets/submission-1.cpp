class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        ans.push_back(tmp);
        for(int i = 0 ; i < nums.size(); i++) {
            int n = ans.size();
            for(int j = 0; j < n; j++) {
                tmp = ans[j];
                tmp.push_back(nums[i]);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
