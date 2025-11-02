// Last updated: 11/2/2025, 10:31:33 PM
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int radius = 0;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int j = 0;
        for(int i=0;i<houses.size();i++)
        {
            int currhouse = houses[i];
            int left,right;
            while(j<heaters.size()-1 && heaters[j]<=currhouse)
            {
                j++;
            }
            if(j>0)
            {
                left = abs(currhouse - heaters[j-1]);
            }
            else
            {
                left = abs(currhouse - heaters[0]);
            }
            right = abs(currhouse - heaters[j]);
            int curmin = min(left,right);
            radius = max(radius,curmin);
        }
        return radius;
    }
};