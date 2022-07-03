// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        int currmax = 0;
        vector<int>left(n);
        vector<int>right(n);
        for(int i=0;i<n;i++)
        {
            currmax = max(currmax,arr[i]);
            left[i] = currmax;
        }
        currmax = 0;
        for(int i=n-1;i>=0;i--)
        {
            currmax = max(currmax,arr[i]);
            right[i] = currmax;
        }
        long long wotah = 0;
        for(int i=0;i<n;i++)
        {
            int water = min(left[i],right[i]);
            wotah = wotah + (water - arr[i]);
        }
        return wotah;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends