class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<vector<int>>v;
        for(int i=0;i<n;i++)
        {
            int diff = abs(x-arr[i]);
            vector<int>temp;
            temp.push_back(diff);
            temp.push_back(arr[i]);
            v.push_back(temp);
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i][1]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};