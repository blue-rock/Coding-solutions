// Last updated: 1/9/2026, 8:37:05 AM
1class Solution {
2public:
3    bool isUgly(int n) {
4        if(n<=0){
5            return false;
6        }
7        while(true){
8            if(n==1 || n==-1){
9                return true;
10            }
11            if(n%2==0 || n%3==0 || n%5==0){
12                if(n%2==0){
13                    n = n/2;
14                }
15                else if(n%3==0){
16                    n = n/3;
17                }
18                else if(n%5==0){
19                    n = n/5;
20                }
21                else{
22                    return false;
23                }
24
25            }
26            else{
27                return false;
28            }   
29        }
30        return false;
31    }
32};