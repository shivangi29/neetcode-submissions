class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int i = 1, n =arr.size(), cur_max = 1, ans = 1;
        if(n <= 1) return n;
        bool small = true, large = true;
        while(i<n) {
            if(arr[i] == arr[i-1]) {
                ans = max(cur_max,ans);
                cur_max = 1;
                small = true;
                large = true;
            } else if(small) {
                if(arr[i] < arr[i-1]) {
                    cur_max += 1;
                    small = false;
                    large = true;
                } else {
                    ans = max(cur_max,ans);
                    cur_max = 2;
                    small = true;
                    large = false;
                }
            } else {
                if(arr[i] > arr[i-1]) {
                    cur_max += 1;
                    small = true;
                    large = false;
                } else {
                    ans = max(cur_max,ans);
                    cur_max = 2;
                    small = false;
                    large = true;
                }
            } 
            i++;
        }
        return max(ans,cur_max);
    }
};