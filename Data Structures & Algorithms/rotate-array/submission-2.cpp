class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = n;
        int i = 0;
        int tmp = nums[i];
        int t = 0;
        while(count) {
            int j = (i+k)%n;
            int tmp2 = nums[j];
            nums[j] = tmp;
            tmp = tmp2;
            count--;
            if(j == t) {
                i = (i+1)%n;
                t = i%n;
                tmp = nums[i];
            }
            else i = j;
        }    
    }
};