class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int t[n];
        for(int i=0; i<n; i++) t[i] = -1;
        return min(fun(cost, n-1, t), fun(cost, n-2, t));
    }
    
    int fun(vector<int>& cost, int n, int* t){
        if(n<0)return 0;
        if(n==0 || n==1 ) return cost[n];
        if(t[n] != -1) return t[n];
        t[n] = cost[n] + min(fun(cost, n-1, t), fun(cost, n-2, t));
        return t[n];
    }
    
};