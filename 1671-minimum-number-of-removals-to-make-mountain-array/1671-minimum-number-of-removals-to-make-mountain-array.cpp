class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int>lis(n,1);
        vector<int>lds(n,1);
        //for lis
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    lis[i] = max(lis[i],lis[j] + 1);
                }
            }
            cout<<lis[i]<<endl;
        }
        //for lds
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]>nums[j])
                {
                    lds[i] = max(lds[i],lds[j]+1);
                }
            }
            cout<<lds[i]<<endl;
        }
        int minval = INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(lis[i]==1 || lds[i]==1)
            {
                continue;
            }
            minval = min(minval,n- (lds[i] + lis[i] -1));
        }
        return minval;
    }
};
//https://www.youtube.com/watch?v=nW4Kx41G7XE