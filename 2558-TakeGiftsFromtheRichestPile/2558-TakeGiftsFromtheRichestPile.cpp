// Last updated: 1/27/2026, 12:02:34 AM
1class Solution {
2public:
3    long long pickGifts(vector<int>& gifts, int k) {
4        int n = gifts.size();
5        while(k>0){
6            int curr_max = INT_MIN;
7            int idx = 0;
8            for(int i=0;i<n;i++){
9                if(gifts[i]>curr_max){
10                    curr_max = gifts[i];
11                    idx = i;
12                }
13            }
14            gifts[idx] = sqrt(gifts[idx]);
15            k--;
16        }
17        long long ans = 0;
18        for(int i=0;i<gifts.size();i++){
19            ans += gifts[i];
20        }
21        return ans;
22        
23    }
24};