class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> idxx(26, vector<int>(1, -1)); 
        for (int i = 0; i < s.size(); ++i)
        {
            idxx[s[i] - 'A'].push_back(i); 
        }
        
        int ans = 0; 
        for (int i = 0; i < 26; ++i) 
        {
            idxx[i].push_back(s.size()); 
            for (int k = 1; k < idxx[i].size()-1; ++k) 
            {
               ans += (idxx[i][k] - idxx[i][k-1]) * (idxx[i][k+1] - idxx[i][k]);  
            }   
        }
        return ans; 
    }
};