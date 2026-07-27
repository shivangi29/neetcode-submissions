class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n,0);
        vector<int> jud(n,0);
        
        for(int i = 0 ; i < trust.size(); i++) {
            count[trust[i][1] - 1] += 1;
            jud[trust[i][0] - 1] += 1;
        }
        int num = 0;
        int judge = -1;
        for(int i = 0 ; i < n; i++) {
            if(count[i] == n-1) {
                num++;
                if(num > 1) return -1;
                if(jud[i] == 0)
                    judge = i+1;
            }   
        }
        return judge;
    }
};