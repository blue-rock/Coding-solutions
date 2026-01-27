// Last updated: 1/28/2026, 12:33:59 AM
1class Solution {
2public:
3    string longestDiverseString(int a, int b, int c) {
4        priority_queue<pair<int,char>>pq;
5        if (a > 0) pq.push({a, 'a'});
6        if (b > 0) pq.push({b, 'b'});
7        if (c > 0) pq.push({c, 'c'});
8        string ans = "";
9        while(!pq.empty()){
10            pair<int,char>curr_pair = pq.top();
11            pq.pop();
12            if(ans.size() >= 2 &&
13            ans[ans.size()-1] == curr_pair.second &&
14            ans[ans.size()-2] == curr_pair.second){
15                if(pq.empty()){
16                    break;
17                }
18                pair<int,char>second_pair = pq.top();
19                pq.pop();
20                ans = ans + second_pair.second;
21                second_pair.first--;
22                if(second_pair.first>0){
23                    pq.push(second_pair);
24                }
25
26            }
27            else{
28                ans = ans + curr_pair.second;
29                curr_pair.first--;
30            }
31            if(curr_pair.first>0){
32                    pq.push(curr_pair);
33            }
34        }
35        return ans;
36
37    }
38};