class Solution {
public:
    set<vector<int>> ans;
    void findSubs(vector<int> tmp, vector<int>& nums, int i) {
        if(i>=nums.size()){
            return;
        }
        for(int j = i; j < nums.size(); j++) {
            tmp.push_back(nums[j]);
            ans.insert(tmp);
            findSubs(tmp, nums, j+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        findSubs({}, nums, 0);
        vector<vector<int>> res(ans.begin(), ans.end());
        res.push_back({});
        return res;
    }
};
