class Solution {
public:
    set<vector<int>> ans;
    void findSubs(vector<int> tmp, vector<int>& nums, int i) {
        if(i>=nums.size()){
            sort(tmp.begin(), tmp.end());
            ans.insert(tmp);
            return;
        }
        findSubs(tmp, nums, i+1);
        tmp.push_back(nums[i]);
        findSubs(tmp, nums, i+1);
        tmp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        findSubs({}, nums, 0);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};
