class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int low = 0;
        int high = (m * n) - 1; // Total elements - 1
        
        while (low <= high) {
            int mid = low + (high - low) / 2; // Prevents integer overflow
            
            // Map 1D index back to 2D coordinates (row, col)
            int row = mid / n;
            int col = mid % n;
            
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};
