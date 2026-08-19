class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        vector<int> ma(n);
        vector<int> mi(n);
        ma[0] = nums[0];
        mi[0] = nums[0];
        for(int i = 1 ; i < n; i++) {
            ma[i] = max(nums[i], max(ma[i-1]*nums[i],  mi[i-1]*nums[i]));
            mi[i] = min(nums[i], min(mi[i-1]*nums[i], ma[i-1]*nums[i]));
        }
        for(int i = 0 ; i < n; i++) {
            //cout<<mi[i]<<" "<<ma[i]<<endl;
            res = max(res, max(mi[i], ma[i]));    
        }
        return res;
    }
};
