class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0 , j = 0;
        int m = nums1.size(), n = nums2.size();
        vector<int> arr;
        
        while(i < m || j < n){
            if(i==m) {
                arr.push_back(nums2[j++]);
            } else if(j==n) {
                arr.push_back(nums1[i++]);
            } else if(nums1[i] < nums2[j]) {
                arr.push_back(nums1[i++]);
            } else {
                arr.push_back(nums2[j++]);
            }
        }
        int mid = (m+n)/2;
        if((m+n) % 2)
            return arr[mid];
        return ((double)arr[mid]+arr[mid-1])/2;
    }
};
