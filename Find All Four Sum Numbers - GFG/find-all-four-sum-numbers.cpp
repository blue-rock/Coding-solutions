// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        set<vector<int>>st;
        for(int i=0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                for(int p=j+1;p<n;p++)
                {
                    int rem =  k - (arr[i] + arr[j] + arr[p]);
                    if(binary_search(arr.begin()+p+1,arr.end(),rem))
                    {
                        vector<int>v  = {rem,arr[i],arr[j],arr[p]};
                        sort(v.begin(),v.end());
                        st.insert(v);
                    }
                }
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends