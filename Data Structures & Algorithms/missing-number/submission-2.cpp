class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_set hash(nums.begin(), nums.end());
        int i = 0;
        for(i = 0 ; i < n ; i++) {
            if(hash.contains(i) == false)
                break;
        }
        return i; 
    }
};
