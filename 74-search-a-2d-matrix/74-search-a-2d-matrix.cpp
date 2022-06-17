class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while( low < high )
        {
            int mid = low + (high-low)/2;
            if( matrix[mid][right] == target )
            {
                return true ;
            }
            else if( target > matrix[mid][right] )
            {
                low = mid + 1 ;
            }
            else
            {
                high = mid ;
            }
        }
        while( left <= right )
        {
            int mid = left + (right-left)/2;
            if( target == matrix[high][mid] )
            {
                return true ;
            }
            else if( target > matrix[high][mid] )
            {
                left = mid + 1 ;
            }
            else
            {
                right = mid - 1 ;
            }
        }
        return false ;
    }
};