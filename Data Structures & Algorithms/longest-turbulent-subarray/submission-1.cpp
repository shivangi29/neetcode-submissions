class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int i = 1, n =arr.size(), cur_max = 1, ans = 1;
        if(n <= 1) return n;
        bool small = true;
        while(i<n) {
            if(arr[i] == arr[i-1]) {
                ans = max(cur_max,ans);
                cur_max = 1;
                small = true;
            } else if(small) {
                if(arr[i] < arr[i-1]) {
                    cur_max += 1;
                    small = false;
                } else {
                    ans = max(cur_max,ans);
                    cur_max = 2;
                    small = true;
                }
            } else {
                if(arr[i] > arr[i-1]) {
                    cur_max += 1;
                    small = true;
                } else {
                    ans = max(cur_max,ans);
                    cur_max = 2;
                    small = false;
                }
            } 
            i++;
        }
        return max(ans,cur_max);
    }
};