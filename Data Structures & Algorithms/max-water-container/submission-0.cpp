class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int ans = 0;
        while(i<j) {
            int tmp =   (j-i)*min(heights[j], heights[i]);
            ans = max(ans, tmp);
            if(heights[j] < heights[i]) {
                j--;
            } else if(heights[j] > heights[i]) {
                i++;
            } else {
                i++; j--;
            }
        }   
        return ans;
    }
};
