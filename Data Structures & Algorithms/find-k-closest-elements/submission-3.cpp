class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int st = 0;
        for(int i = 1 ; i <= arr.size()-k; i++) {
            int l = abs(arr[st]-x);
            int r = abs(arr[i+k-1]-x);
           
            if(r < l) {
                st = i;
            }
        }
        vector<int> ans(arr.begin()+st, arr.begin()+st+k);
        return ans;
    }
};