class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>mat(n,vector<int>(n));
        int dir = 0;
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        int num = 1;
        while(top<=bottom && left<=right)
        {
            if(dir==0)
            {
                for(int i=left;i<=right;i++)
                {
                    mat[top][i] = num;
                    num++;
                }
                top++;
            }
            else if(dir==1)
            {
                for(int i=top;i<=bottom;i++)
                {
                    mat[i][right] = num;
                    num++;
                }
                right--;
            }
            else if(dir==2)
            {
                for(int i=right;i>=left;i--)
                {
                    mat[bottom][i] = num;
                    num++;
                }
                bottom--;
            }
            else if(dir==3)
            {
                for(int i=bottom;i>=top;i--)
                {
                    mat[i][left] = num;
                    num++;
                }
                left++;
            }
            dir = (dir+1)%4;
        }
        return mat;
    }
};