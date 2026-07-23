class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int>front(n+2,1);
        vector<int>back(n+2,1);

        for(int i = 1 ; i <= n; i++){
            front[i] = front[i-1] * nums[i-1];
        }
        for(int i = n ; i >=1; i--){
            back[i] = back[i+1] * nums[i-1];
        }

        for(int num : front)
            cout<<num<<" ";
        cout<<endl;

        for(int num : back)
            cout<<num<<" ";

        for(int i = 1 ; i <= n ;i++) {
            ans.push_back(back[i+1]*front[i-1]);
        }

        return ans;
    }
};
