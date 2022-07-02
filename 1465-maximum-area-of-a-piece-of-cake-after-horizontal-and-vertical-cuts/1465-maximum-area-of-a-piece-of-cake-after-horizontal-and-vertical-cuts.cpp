class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int hmax = 0;
        int mod = 1e9 + 7;
        for(int i=0;i<horizontalCuts.size()-1;i++)
        {
            hmax = max(hmax,horizontalCuts[i+1] - horizontalCuts[i]);
        }
        hmax = hmax%mod;
        int vmax = 0;
        for(int i=0;i<verticalCuts.size()-1;i++)
        {
            vmax = max(vmax,verticalCuts[i+1] - verticalCuts[i]);
        }
        vmax = vmax%mod;
        return ((long)hmax*vmax) % (int)mod;
    }
};