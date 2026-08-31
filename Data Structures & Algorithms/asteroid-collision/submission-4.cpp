class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(auto a : asteroids){
            ans.push_back(a);
            while(ans.size() > 1) {
                int b = ans[ans.size()-1];
                int a = ans[ans.size()-2];
                if((a>0 && b>0) || (a<0 && b<0) || (a<b))
                    break;
                ans.pop_back();
                if(abs(a) < abs(b)) {
                    ans[ans.size()-1] = b; 
                } else if(abs(a) == abs(b)) {
                    ans.pop_back();
                }
            }
        }
        return ans;
    }
};