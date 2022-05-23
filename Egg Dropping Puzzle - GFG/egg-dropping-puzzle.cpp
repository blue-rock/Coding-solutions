// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor
    int eggDrop(int eggs, int floors) 
    {
        // your code here
        vector<vector<int>>memo(eggs+1,vector<int>(floors+1,-1));
        return find(eggs,floors,memo);
    }
    int find(int eggs,int floors,vector<vector<int>>& memo)
    {
        if(floors==0 || floors==1)
        {
            return floors;
        }
        if(eggs==1)
        {
            return floors;
        }
        if(memo[eggs][floors]!=-1)
        {
            return memo[eggs][floors];
        }
        int ans = INT_MAX;
        for(int i=1;i<=floors;i++)
        {
            int temp = 1 + max(find(eggs-1,i-1,memo),find(eggs,floors-i,memo));
            ans = min(ans,temp);
        }
        return memo[eggs][floors] = ans;
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends