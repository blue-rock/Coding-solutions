// Last updated: 11/2/2025, 10:27:55 PM
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n<m*k)
        {
            return -1;
        }
        int left = *min_element(bloomDay.begin(),bloomDay.end());
        int right = *max_element(bloomDay.begin(),bloomDay.end());
        while(left<right)
        {
            int mid = left + (right-left)/2;
            int c = 0; //adj count
            int bouq = 0;
            for(int i=0;i<n;i++)
            {
                if(bloomDay[i]<=mid)
                {
                    c++;
                }
                else
                {
                    c=0;
                }
                if(c==k)
                {
                    bouq++;
                    c=0;
                }
            }
            if(bouq<m)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};