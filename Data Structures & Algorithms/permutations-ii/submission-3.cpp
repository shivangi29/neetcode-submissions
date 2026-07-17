class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return res;
    }
    /*void printV(vector<int> nums) {
        for (int x : nums)
            cout<<x<<" ";
        cout<<endl;
    }*/
    void backtrack(vector<int>& nums, int idx) {
        if(idx >= nums.size()) {
       //     printV(nums);
            res.push_back(nums);
            return;
        }
        for(int i = idx; i < nums.size(); i++) {
            if(i > idx && nums[i] == nums[idx]) 
                continue;
            swap(nums[i], nums[idx]);
            backtrack(nums, idx+1);
        }
        for (int j = nums.size() - 1; j > idx; --j) {
            swap(nums[j], nums[idx]);
        //while(i-1nums[])
        }
    }
};