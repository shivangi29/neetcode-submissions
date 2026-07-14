class Solution {
public:
    void findSets(int i, vector<int>& tmp, vector<int>& nums, vector<vector<int>>& ans){
        if(i >= nums.size()){
            ans.push_back(tmp);
            return;
        }
        findSets(i+1, tmp, nums, ans);
        tmp.push_back(nums[i]);
        findSets(i+1, tmp, nums, ans);
        tmp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp; 
        findSets(0, tmp, nums, ans);
        return ans;
    }
};
