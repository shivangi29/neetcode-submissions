class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        // Step forward through the array starting at index 2
        for (int i = 2; i < n; i++) {
            // The cost to stand here is its own cost plus the cheaper of the last two steps
            cost[i] += min(cost[i-1], cost[i-2]);
        }
        
        // The answer is the cheaper of the final two steps
        return min(cost[n-1], cost[n-2]);
    }
};
