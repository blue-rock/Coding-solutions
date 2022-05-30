class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                matrix[i][j] = matrix[i][j] + matrix[i][j-1];
            }
        }
        int ans = 0;
        unordered_map<int,int>mp;
        int count = 0;
        for(int start=0;start<m;start++)
        {
            for(int startcol=start;startcol<m;startcol++)
            {
                int sum = 0;
                mp.clear();
                mp[0]++;
                for(int rows=0;rows<n;rows++)
                {
                    if(start>0)
                    {
                        sum = sum +matrix[rows][startcol] - matrix[rows][start-1];       
                    }
                    else
                    {
                        sum = sum + matrix[rows][startcol];
                    }
                    count = count + mp[sum - target];
                    mp[sum]++;
                }
            }
        }
        return count;
        
    }
};