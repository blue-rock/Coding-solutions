// Last updated: 11/2/2025, 10:29:17 PM
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>res;
        int p1 = 0;
        int p2 = 0;
        int s1 = firstList.size();
        int s2 = secondList.size();
        vector<int>temp(2);
        
        while(p1<s1 && p2<s2)
        {
            if(secondList[p2][0]<=firstList[p1][1] && firstList[p1][0]<=secondList[p2][1])
            {
                temp[0] = max(firstList[p1][0],secondList[p2][0]);
                temp[1] = min(firstList[p1][1],secondList[p2][1]);
                res.push_back(temp);
            }
            if(firstList[p1][1]>secondList[p2][1])
            {
                p2++;
            }
            else
            {
                p1++;
            }
        }
        return res;
    }
};