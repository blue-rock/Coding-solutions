class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1] + 1, mid, count, tmp;
        
        while (low < high) {
            mid = low + (high - low) / 2, tmp = n - 1, count = 0;
            for (int i = 0; i < n; i++) {
                while (tmp >= 0 && matrix[i][tmp] > mid) tmp--;
                count += tmp + 1;
            }
            
            if (count < k) low = mid + 1;
            else high = mid;
        }
        
        return low;
    }
};