// Last updated: 11/2/2025, 10:28:29 PM
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>sol(n,0);
        if(n==1){
            return sol;
        }
        for(int i=0;i<(n)/2;i++){
            sol[i] = i+1;
            sol[n-i-1] = (i+1)*-1;
        }
        return sol;
    }
};