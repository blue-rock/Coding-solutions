// Last updated: 11/2/2025, 10:31:24 PM
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.size()==0 || mat[0].size()==0)
        {
            vector<int>ans;
            return ans;
        }
        int m = mat.size();
        int n = mat[0].size();
        vector<int>ans(m*n);
        int i = 0;
        int row =  0;
        int col = 0;
        bool up = true;
        while(row<m && col<n)
        {
            //diag going up
            if(up)
            {
                while(row>0 && col<n-1)
                {
                    ans[i] = mat[row][col];
                    i++;
                    row--;
                    col++;
                }
                 ans[i] = mat[row][col];
                 i++;
                if(col==n-1)
                {
                    row++;
                }
                else
                {
                    col ++;
                }
            }
            //fiag going down
            else
            {
             while(col>0 && row<m-1)
             {
                 ans[i] = mat[row][col];
                 i++;
                 row++;
                 col--;
             }
                ans[i] = mat[row][col];
                i++;
                if(row==m-1)
                {
                    col++;
                }
                else
                {
                    row++;
                }
            }
            up = !up;
        }
        return ans;
    }
};