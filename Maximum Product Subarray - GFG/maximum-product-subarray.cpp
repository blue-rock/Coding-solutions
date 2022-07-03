// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
long long max(long long a,long long b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}
long long min(long long a,long long b)
{
    if(a<b)
    {
        return a;
    }
    return b;
}

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long currmin = 1;
	    long long currmax = 1;
	    long long res = INT_MIN;
	    int flag = 0;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]==0)
	        {
	            currmin = 1;
	            currmax = 1;
	            flag = 1;
	            continue;
	        }
	        long long minhere = currmin*arr[i];
	        long long maxhere = currmax*arr[i];
	        currmax = max(maxhere,max(arr[i],minhere));
	        currmin = min(minhere,min(arr[i],maxhere));
	        if(currmax>res)
	        {
	            res=currmax;
	        }
	    }
	    if(res<0 && flag==1)
	    {
	        return 0;
	    }
	    return res;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends