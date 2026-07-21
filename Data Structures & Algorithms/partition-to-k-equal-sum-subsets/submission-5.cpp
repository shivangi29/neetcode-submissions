class Solution {
public:
    map<int, int> hash;
    int req;
    bool findPart(int len, int sum, int tot, int n){
        if(len == 0) {
            tot++;
            len = sum;
            //cout<<tot<<endl;
            //cout<<endl;
        }
        if(tot == req && n == 0) {
            return true;
        }
        for(auto &[a,b] : hash) {
            if(a > len)
                return false;
            if(b) {
                b--;
                if(findPart(len-a, sum, tot, n-1))
                    return true;
                b++;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        hash.clear();
        int sum = 0;
        for(int num : nums) {
            sum+=num;
        }
        if(sum%k)
            return false;
        
        int len = sum/k;

        //cout<<target<<endl;
        for(int num : nums) {
            hash[num]++;
            if(num > len)
                return false;
        }
        req = k;
        return findPart(len, len, 0, nums.size());
    }
};