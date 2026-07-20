class Solution {
public:
    int target = 0;
    bool findPart(vector<int>& nums, vector<int>& subset, int i){
        if(i == nums.size()) {
            for(int num : subset) {
                if(num!=target)
                    return false;
            }
            //cout<<endl;
            return true;
        }
        for(int j = 0 ; j < subset.size(); j++) {
            if(subset[j] + nums[i] <= target) {
                subset[j] += nums[i];
                if(findPart(nums, subset, i+1))
                    return true;
                subset[j] -= nums[i];
            }
        }
        //for(int num : subset) {
          //  cout<<num<<" ";
        //}
        //cout<<endl;
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int num : nums) {
            sum+=num;
        }
        //cout<<sum<<endl;
        if(sum%k)
            return false;
        
        target = sum/k;

        //cout<<target<<endl;
        for(int num : nums) {
            if(num > target)
                return false;
        }
        vector<int> subset(k, 0);
        sort(nums.rbegin(), nums.rend());
        return findPart(nums, subset, 0);
    }
};