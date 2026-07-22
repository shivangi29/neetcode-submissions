class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(int num : nums) {
            hash[num]++;
        }
        vector<pair<int,int>> tmp;
        for(auto &[a,b] : hash) {
            tmp.push_back({b,a});
        }
        sort(tmp.rbegin(), tmp.rend());
        vector<int> ans;
        int i = 0;
        while(i < k) {
            ans.push_back(tmp[i].second);
            i++;
        }
        return ans;
    }
};
