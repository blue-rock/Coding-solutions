// Last updated: 11/2/2025, 10:27:58 PM
typedef pair<int, int> pi;
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int>arr2 = arr;
        sort(arr.begin(),arr.end());
         priority_queue<pi, vector<pi>, greater<pi> > pq;
        int medval = 0;
        if(arr.size()==0)
        {
            return arr;
        }
        if(arr.size()==1)
        {
            return arr;
        }
        if(arr.size()%2==0)
        {
            // medval = (arr[arr.size()/2] + arr[arr.size()/2 - 1])/2;
            medval = arr[arr.size()/2 -1];
        }
        else 
        {
            medval = arr[arr.size()/2];
        }
        for(int i=0;i<arr.size();i++)
        {
            int sval = abs(arr2[i] - medval);
            pq.push(make_pair(sval,arr2[i]));
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<int>retv;
        while(!pq.empty())
        {
            retv.push_back(pq.top().second);
            pq.pop();
        }
        reverse(retv.begin(),retv.end());
        return retv;
    }
};
