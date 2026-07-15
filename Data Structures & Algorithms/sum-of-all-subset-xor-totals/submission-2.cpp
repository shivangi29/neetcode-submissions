class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> tmp;
        tmp.push_back(0);
        int ans = 0;
        for(int i = 0 ; i < nums.size(); i++) {
            int n = tmp.size();
            for(int j = 0; j < n; j++) {
                ans += nums[i]^tmp[j];
                tmp.push_back(nums[i]^tmp[j]);
            }
        }
        return ans;
    }
};

