// Last updated: 11/2/2025, 10:32:22 PM
class Solution {
public:
    int l,u;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long int>x(n+1,0);
        int res = 0;
        l = lower;
        u = upper;
        for(int i=0;i<n;i++)
        {
            x[i+1] = x[i] + nums[i];
        }
        merge(x.begin(),x.end(),res);
        return res;
    }
    void merge(vector<long long int>::iterator start,vector<int long long>::iterator end, int&res)
    {
        if(end - start<=1)
        {
            return;
        }
        auto mid = start + (end-start)/2;
        merge(start,mid,res);
        merge(mid,end,res);
        auto j = mid, k=mid;
        for(auto i=start;i!=mid;i++)
        {
            while(j!=end &&*j - *i < l)
            {
                j++;
            }
            while(k!=end && *k - *i <=u)
            {
                k++;
            }
            res = res + k - j;
        }
        inplace_merge(start , mid, end);
    }
};