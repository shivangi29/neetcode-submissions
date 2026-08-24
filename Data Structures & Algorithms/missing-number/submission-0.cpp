class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(auto a : nums)
            res = res^a;
        int n = nums.size();
        for(int i = 0 ; i <=n; i++)
            res = res^i;
        return res; 
    }
};
