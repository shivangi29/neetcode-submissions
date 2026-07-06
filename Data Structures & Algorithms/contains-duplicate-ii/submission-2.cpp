class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k == 0) return false;
        int n = nums.size();
        unordered_map<int,int> hash;
        for(int i = 0 ; i < n; i++) {
            if(hash.contains(nums[i]))
                if(i - hash[nums[i]] <= k)
                    return true;
            hash[nums[i]] = i;
        }
        return false;
    }
};