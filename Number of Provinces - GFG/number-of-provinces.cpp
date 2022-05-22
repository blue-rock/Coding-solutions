// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int count = 0;
        vector<int>visited(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(adj,visited,i,V);
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& adj,vector<int>& visited, int i, int V)
    {
        visited[i] = 1;
        for(int j=0;j<V;j++)
        {
            if(adj[i][j]==1 && !visited[j])
            {
                dfs(adj,visited,j,V);
            }
        }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends