// Last updated: 11/2/2025, 10:29:12 PM
class Solution {
public:
   bool isValid(string s) {
       string v;
       for(int i=0;i<s.length();i++)
       {
           v.push_back(s[i]);//push the character 
           while(v.size()>=3 && v[v.size()-1]=='c' && v[v.size()-2]=='b' && v[v.size() - 3] == 'a' )
           {
               v.pop_back();
               v.pop_back();
               v.pop_back();
           }
       }
       return (bool)(!v.size());
   }
};
