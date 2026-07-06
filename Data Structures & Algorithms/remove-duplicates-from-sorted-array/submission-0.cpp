class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0, i = 0;
        set<int> myHash;
        while(i < nums.size()) {
            if(myHash.find(nums[i]) == myHash.end()){
                myHash.insert(nums[i]);
                nums[k++] = nums[i]; 
            }
            i++;
        }
        return k;
    }
};