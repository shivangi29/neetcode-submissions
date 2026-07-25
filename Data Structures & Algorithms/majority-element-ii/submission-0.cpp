class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        int min = nums.size()/3;
        for(auto num : nums) {
            hash[num]++;
        }
        vector<int> ans;
        for(auto &[a,b] : hash) {
            if(b > min)
                ans.push_back(a);
        }
        return ans;
    }
};