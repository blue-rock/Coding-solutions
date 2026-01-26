// Last updated: 1/26/2026, 11:17:43 PM
1class Solution {
2public:
3    long long maxPoints(vector<vector<int>>& points) {
4        int r = points.size();
5        int c = points[0].size();
6
7        vector<long long> dp (c,0);
8        for(int i=0;i<c;i++){
9            dp[i] = points[0][i];
10        }
11
12        for(int i=1;i<r;i++){
13            vector<long long> left(c), right(c), curr(c);
14
15            left[0] = dp[0];
16            for(int j=1;j<c;j++){
17                left[j] = max(left[j-1]-1, dp[j]);
18            }
19
20            right[c-1] = dp[c-1];
21            for(int j=c-2;j>=0;j--){
22                right[j] = max(right[j+1]-1, dp[j]);
23            }
24
25            for(int j=0;j<c;j++){
26                curr[j] = points[i][j] + max(left[j], right[j]);
27            }
28            dp = curr;
29
30        }
31
32        long long ans = 0;
33        for(auto &h : dp){
34            ans = max(ans,h);
35        }
36        return ans;
37    }
38};