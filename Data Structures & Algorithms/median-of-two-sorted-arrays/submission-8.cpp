class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0 , j = 0;
        int m = nums1.size(), n = nums2.size();
        int k = 0;
        int mid = (m+n)/2;
        while(k < mid){
            if(i==m || (j<n && nums1[i] > nums2[j]))
                j++;
            else i++;
            k++;
        }
        if(m == 0) {
            if(n%2) return nums2[mid];
            return (nums2[mid]+nums2[mid-1])/2.0;
        }
        if(n == 0) {
            if(m%2)  return nums1[mid];
            return (nums1[mid]+nums1[mid-1])/2.0;
        }
        cout<<"i: "<<i<<" j: "<<j<<" k: "<<k<<endl;
        if((m+n) % 2) {
            if(i==m)
                return nums2[j];
            if(j==n)
                return nums1[i];
            return min(nums1[i], nums2[j]);
        }
        if(i==m){
            int a,b;
            if(j == 0) {
                a = nums1[i-1];
            } else {
                a = max(nums1[i-1], nums2[j-1]);
            }
             return (a+nums2[j])/2.0;
        }
        if(j==n) {
            int a,b;
            if(i == 0) {
                a = nums2[j-1];
            } else {
                a = max(nums1[i-1], nums2[j-1]);
            }
            return (a+nums1[i])/2.0;
        }
        int a = min(nums1[i], nums2[j]);
        int b;
        if(i==0)
            b = nums2[j-1];
        else if(j==0)
            b = nums1[i-1];
        else
            b = max(nums1[i-1], nums2[j-1]);
        return (a+b)/2.0;
    }
};
