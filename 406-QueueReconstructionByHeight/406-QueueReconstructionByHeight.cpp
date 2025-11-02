// Last updated: 11/2/2025, 10:31:56 PM
bool cmp(vector<int>&a,vector<int>&b)
{
    if(a[0]==b[0])
    {
        return a[1]<b[1];
    }
    return a[0]>b[0];
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>>res;
        for(auto vec:people)
        {
            res.insert(res.begin()+vec[1],vec);
        }
        return res;
    }
};