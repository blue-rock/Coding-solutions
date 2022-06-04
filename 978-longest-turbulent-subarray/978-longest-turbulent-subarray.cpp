class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n,1);
        dp[0]=1;
        int flag = -1; 
        for(int i=1;i<n;i++)
        {
            if((flag==0||flag==-1) && arr[i]>arr[i-1])
            {
                flag=1;
                dp[i] = dp[i-1]+1;
            }
            else if((flag==1||flag==-1) && arr[i]<arr[i-1])
            {
                flag=0;
                dp[i] = dp[i-1] + 1;
            }
            else
            {
                (arr[i]!=arr[i-1])?dp[i] = 2:1;
                if(arr[i]>arr[i-1])
                {
                    flag = 1;
                }
                else if(arr[i]<arr[i-1])
                {
                    flag = 0;
                }
                else
                {
                    flag = -1;
                }
            }
        }
        return  *max_element(begin(dp), end(dp));
    }
};