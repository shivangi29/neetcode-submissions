class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0, i = 0;
        while(i < nums.size()) {
            int j = i+1;
            while(j < nums.size() && nums[j]==nums[i])
                j++;
            nums[k++] = nums[i];
            i = j;
        }
        return k;
    }
};