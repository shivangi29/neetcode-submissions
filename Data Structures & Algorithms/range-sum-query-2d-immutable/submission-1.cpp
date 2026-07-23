class NumMatrix {
public:
    vector<vector<int>> sumMat;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        sumMat = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for(int i = 0 ; i < m ; i++) {
            int prefix = 0;
            for(int j = 0 ; j < n ;j++) {
                prefix += matrix[i][j];
                sumMat[i+1][j+1] = prefix + sumMat[i][j+1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = sumMat[row2+1][col2+1] - sumMat[row2+1][col1] - sumMat[row1][col2+1] + sumMat[row1][col1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */