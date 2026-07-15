class Solution {
public:
    vector<vector<int>> ans;
    void combo(int i, vector<int>& nums, vector<int>& tmp, int target) {
        if(target == 0) {
            ans.push_back(tmp);
            return;
        }
        for(int j = i ; j < nums.size() && nums[j] <= target ; j++) {
            //cout<<" target "<<target<<" nums "<<nums[j]<<endl;
            if(nums[j] <= target) {
                tmp.push_back(nums[j]);
                combo(j, nums, tmp, target-nums[j]);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> tmp;
        combo(0, nums, tmp, target);
        return ans;
    }
};
