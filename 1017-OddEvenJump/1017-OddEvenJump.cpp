// Last updated: 11/2/2025, 10:29:22 PM
class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<vector<bool>>res(n,vector<bool>(2,false));
        res[n-1] = {true,true};
        map<int,int>mp;
        mp[arr[n-1]] = n-1;
        int count = 1;
        for(int i=n-2;i>=0;i--)
        {
            auto index = mp.lower_bound(arr[i]);
            if(index!=mp.end())
            {
                if(res[index->second][0])
                {
                    res[i][1] = true;
                    count++;
                }
                if(index->first == arr[i])
                {
                    res[i][0] = res[index->second][1];
                }
                else if(index!=mp.begin())
                {
                    index--;
                    res[i][0] = res[index->second][1];
                }
            }
            else
            {
                index--;
                res[i][0] = res[index->second][1];
            }
            mp[arr[i]] = i;
        }
        return count;
        
    }
};