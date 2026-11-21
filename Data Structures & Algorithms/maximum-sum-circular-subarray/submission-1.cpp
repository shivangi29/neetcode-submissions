class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for(int i = 0 ; i < n ;i++) {
            int st = (i+1)%n;
            int sum = nums[i];
            int loc_max = nums[i];
            while(i != st) {
                //cout<<sum<<endl;
                loc_max = max(sum, loc_max);
                if(sum<0)
                    sum = 0;
                sum+=nums[st];
                st = (st+1)%n;
            }
            loc_max = max(sum, loc_max);
            ans = max(loc_max, ans);
        }
        return ans;
    }
};
