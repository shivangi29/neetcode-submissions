class Solution {
public:
    void mergeSort(int l, int r, vector<int>& nums) {
        
        if(l == r) return;
        int m = (r+l)/2;
        mergeSort(l, m, nums);
        mergeSort(m+1,r,nums);

        vector<int> arr(r-l+1, 0);
        int k = 0;
        int i = l, j = m+1;
        while(i<=m && j<=r) {
            if(nums[i] > nums[j]) {
                arr[k++] = nums[j++];
            } else { 
                arr[k++] = nums[i++];
            }
        }
        while(i <= m) {
            arr[k++] = nums[i++];
        }
        while(j <= r) {
            arr[k++] = nums[j++];
        }
        k = 0;
        for(i = l; i <= r; i++) {
            nums[i] = arr[k++];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0,nums.size()-1,nums);
        return nums;
    }
};