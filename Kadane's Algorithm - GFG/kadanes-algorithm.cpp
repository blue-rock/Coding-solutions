// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int max(int a,int b)
    {
        if(a>b)
        {
            return a;
        }
        return b;
    }
    long long maxSubarraySum(int arr[], int n){
        long long sum = INT_MIN;
        int curr = 0;
        for(int i=0;i<n;i++)
        {
            curr = max(arr[i],curr + arr[i]);
            sum = max(sum,curr);
        }
        return sum;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends