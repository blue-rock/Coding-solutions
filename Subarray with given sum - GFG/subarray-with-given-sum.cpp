// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
     vector<int> subarraySum(int a[], int n, long long sum)
    {
        // Your code here
        int left = 0;
        int right = 0;
        long long int curr = 0;

        while(left<n) 
        {
            if(curr == sum)
            {
                return {left+1,right};
            }
            
            if(curr < sum) 
            {
                curr+=a[right];
                right++;
            }
            else
            {
                curr = curr - a[left];
                left++;
            }
        }
        return {-1};
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends