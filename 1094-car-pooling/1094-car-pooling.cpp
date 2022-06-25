class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<vector<int>>pnd;
        int n = trips.size();
        for(auto t:trips)
        {
            pnd.push_back({t[1],t[0]});
            pnd.push_back({t[2],-t[0]});
        }
        sort(pnd.begin(),pnd.end());
        int pass = 0;
        for(int i=0;i<2*n;i++)
        {
            pass = pass + pnd[i][1];
            if(pass>capacity)
            {
                return false;
            }
        }
        return true;
    }
};