class Solution {
public:
    bool dfs(vector<int>& matchsticks, vector<int>&v, int index, int target){
        if(index == matchsticks.size()){
            return true;
        }
        for(int i = 0; i < 4; i++){
            if((v[i] + matchsticks[index] > target) || (i > 0 && v[i] ==v[i - 1])){
                continue;
            }
            v[i] += matchsticks[index];
            if(dfs(matchsticks,v, index+1, target))
            {
                return true;
            }
            v[i] -= matchsticks[index];
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(int i : matchsticks){
            sum += i;
        }
        if(sum%4 != 0 or matchsticks.size() < 3){
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end());
        reverse(matchsticks.begin(),matchsticks.end());
        vector<int>v(4, 0);
        return dfs(matchsticks,v, 0, sum/4);
    }
};

    
    