class Solution {
public:
    vector<vector<int>> ans;
    void find2Sum(long long sum, int st, int nd, int i, vector<int> nums) {
        int j = nums.size()-1;
        while(i < j) {
            int tar = nums[i] + nums[j];
            cout<<tar<<" "<<sum<<endl;
            if(tar == sum) {
                ans.push_back({st,nd,nums[i], nums[j]});
                i++; j--;
                while(i<j && (nums[i] == nums[i-1]))
                    i++;
            } else if(tar < sum) {
                i++;
            } else {
                j--;
            }
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        cout<<target<<endl;
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < n; i++) {
            if(i > 0 && (nums[i-1]==nums[i]))
                continue;
            for(int j = i+1; j < n; j++) {
                if(j > i+1 && (nums[j-1]==nums[j]))
                    continue;
                long long sum = (long long)target - nums[i] - nums[j];
                cout<<"sum "<<sum<<endl;
                find2Sum(sum, nums[i], nums[j], j+1, nums);
            }
        }
        return ans;
    }
};