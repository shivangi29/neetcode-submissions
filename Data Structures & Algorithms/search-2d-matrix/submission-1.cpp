class Solution {
public:
    bool bs(vector<int>& arr, int target) {
        int l = 0, h = arr.size()-1;
        while(l<=h) {
            int m = (l+h)>>1;
            if(arr[m] == target) 
                return true;
            else if(arr[m] < target)
                l = m+1;
            else 
                h = m-1; 
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int low = 0, high = m-1;
        while(low <= high) {
            //cout<<" "<<low<<" "<<high<<" "<<endl;
            int mid = (low+high)>>1;
            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0] > target)
                high = mid - 1;
            else 
                low = mid + 1; 
        }
        
        if(high < 0 || high >= m) return false;
        return bs(matrix[high], target);
    }
};
