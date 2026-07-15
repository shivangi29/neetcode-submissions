class Solution {
public:
    vector<vector<int>> ans;
    void combo(vector<int>& arr, int target, vector<int> tmp, int i) {
        if(target == 0){
            ans.push_back(tmp);
            return;
        }
        if(i >= arr.size())
            return;
        int j = i;
        while(j < arr.size() && arr[j] <= target) {
            tmp.push_back(arr[j]);
            combo(arr, target-arr[j], tmp, j+1);
            tmp.pop_back();
            while(j+1<arr.size() && arr[j]==arr[j+1])
                j++;
            j++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        sort(candidates.begin(), candidates.end());
        combo(candidates,target,{}, 0);
        //vector<vector<int>> res(ans.begin(), ans.end());
        return ans;
    }
};
