// Last updated: 11/2/2025, 10:27:06 PM
class Solution {
public:
    bool canChange(string start, string target) {
        int st1 = 0;
        int st2 = 0;
        int en1 = 0;
        int en2 = 0;
        for(auto c : start) { 
            if(c=='L')
            {
                st1++;
            }
            else if(c=='R')
            {
                en1++;
            }
        }
        for(auto c : target) { 
            if(c=='L')
            {
                st2++;
            }
            else if(c=='R')
            {
                en2++;
            }
        }
         if(st1==st2  && en1==en2){ 
            vector<int>check1;
            vector<int>check2;
            for(int i = 0;i<start.size();i++){ 
                if(start[i] != '_')
                {
                    check1.push_back(i);
                }
            }
            for(int i = 0;i<target.size();i++){ 
                if(target[i] != '_') 
                {
                    check2.push_back(i);
                }
            }
            bool flag = 1;
            for(int i = 0;i<check1.size();i++){ 
                if(start[check1[i]] != target[check2[i]])
                {
                    flag = 0;
                }
                else { 
                    if(start[check1[i]] == 'L')
                    { 
                        if(check1[i] < check2[i])
                        {
                            flag = 0;
                        }
                    }
                    else 
                    { 
                        if(check1[i] > check2[i])
                        {
                            flag = 0;
                        }
                        
                    }
                }

            }
            return flag;
        }
        return false;
        
    }
};