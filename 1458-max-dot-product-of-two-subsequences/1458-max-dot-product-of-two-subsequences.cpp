class Solution {
public:
    int sum;
    int dp[502][502][2];
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<502;i++)
        {
            for(int j=0;j<502;j++)
            {
                dp[i][j][0] = INT_MIN;
                dp[i][j][1] = INT_MIN;
            }
        }
        int ans = operate(nums1,nums2,0,0,0);
        if(ans==-1)
        {
            sort(nums1.begin(),nums1.end());
            sort(nums2.begin(),nums2.end());
            return max(nums1.front()*nums2.back(),nums1.back()*nums2.front());
        }
        return ans;
    }
    int operate(vector<int>&nums1,vector<int>&nums2,int s1,int s2,int l)
    {
        if(s1==nums1.size() || s2==nums2.size())
        {
            if(l==1)
            {
                return 0;
            }
            return -1;
        }
        if(dp[s1][s2][l]!=INT_MIN)
        {
            return dp[s1][s2][l];
        }
        int op1 = nums1[s1]*nums2[s2] + operate(nums1,nums2,s1+1,s2+1,1);
        int op2 = operate(nums1,nums2,s1,s2+1,l);
        int op3 = operate(nums1,nums2,s1+1,s2,l);
        return dp[s1][s2][l] = max(op1,max(op2,op3));
    }
};