class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res ;
        vector<string> temp ;
        helper(res , temp , s ,0) ;
        return res ;
    }
    
    void  helper(vector<vector<string>>& res , vector<string>& temp, string &s ,int idx)
    {
        if (idx == s.length())
        {
            res.push_back(temp) ;
            return ;
        }
        
        for (int i=idx;i<s.length();i++)
        {
            if (ispal(s,idx,i))
            {
                temp.push_back(s.substr(idx,i-idx+1)) ;
                helper(res ,temp ,s , i+1);
                temp.pop_back() ;
            }
        }
    }
    
    bool ispal (string &s , int l , int r)
    {
        while (l <=r)
        {
            if (s[l] != s[r]) return false ;
            
            l++ ; r-- ;
        }
        return true ;
    }
};