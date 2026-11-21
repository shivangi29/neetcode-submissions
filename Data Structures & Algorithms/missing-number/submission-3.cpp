class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int req = 0;
        for(int i = 0 ; i <= n ; i++) {
            req = req ^ i;
        }
        for(auto &ele : nums) {
            req = req ^ ele;
        }
        //0 1 2 3
        return req; 
    }
};
