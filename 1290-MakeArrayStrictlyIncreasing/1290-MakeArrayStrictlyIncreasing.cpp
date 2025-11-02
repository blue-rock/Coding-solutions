// Last updated: 11/2/2025, 10:28:44 PM
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        vector<unordered_map<int,int>>dp(2001);
        sort(arr2.begin(),arr2.end());
        int val = check(0,INT_MIN,arr1,arr2,dp);
        if(val!=INT_MAX)
        {
        return val;
        }
        return -1;
    }
    int check(int index, int left,vector<int>& arr1,vector<int>& arr2,vector<unordered_map<int,int>>& dp)
    {
        if(index == arr1.size())
        {
            return 0;
        }
        if(dp[index].find(left)!=dp[index].end())
        {
            return dp[index][left];
        }
        int res1,res2;
        if(arr1[index]>left)
        {
            res1 = check(index+1,arr1[index],arr1,arr2,dp);
        }
        else
        {
            res1 = INT_MAX;
        }
        int rep = upper_bound(arr2.begin(),arr2.end(),left) - arr2.begin();
        if(rep==arr2.size())
        {
            res2 = INT_MAX;
        }
        else
        {
            res2 = check(index+1,arr2[rep],arr1,arr2,dp);
        }
        if(res2==INT_MAX)
        {
            dp[index][left] = res1;
        }
        else
        {
            dp[index][left] = min(res1,res2+1);
        }
        return dp[index][left];
    }
};