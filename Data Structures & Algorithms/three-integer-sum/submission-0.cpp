class Solution {
public:
    void find2Sum(vector<vector<int>>& ans, vector<int> nums, int num, int i) {
        int target = 0 - num;
        int j = nums.size() - 1;
        while(i<j) {
            int tmp = nums[i] + nums[j];
            if(tmp == target) {
                ans.push_back({num, nums[i], nums[j]});
                i++; j--;
                while(i<j && nums[i] == nums[i-1]) 
                    i++;
                while(i<j && nums[j] == nums[j+1]) 
                    j--;
            } else if(tmp < target) {
                i++;
                while(i<j && nums[i] == nums[i-1]) 
                    i++;
            } else {
                j--;
                while(i<j && nums[j] == nums[j+1]) 
                    j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size()-2 ; i++) {
            if(i > 0 && i < nums.size()-2 && nums[i] == nums[i-1]) {
                //cout << nums[i]<<" "<<nums[i-1]<<endl;
                continue;
            }
            find2Sum(ans, nums, nums[i], i+1);
        }
        return ans;
    }
};
