// Last updated: 11/3/2025, 8:57:47 AM
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int s = neededTime.size();
        int ans = 0;
        for(int i=1;i<s;i++){
            if(colors[i]!=colors[i-1]){
                continue;
            }
            else{
                int maxTime = neededTime[i-1];
                int total_time = neededTime[i-1];
                while(colors[i]==colors[i-1] && i<s){
                    total_time += neededTime[i];
                    maxTime = max(maxTime, neededTime[i]);
                    i++;
                }
                ans += total_time - maxTime;
            }
        }
        return ans;
    }
};