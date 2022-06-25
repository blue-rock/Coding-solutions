class Solution {
public:
    string removeKdigits(string num, int k) {
        string v="";
        for(int i=0;i<num.size();i++){
                while(v.size()!=0 && num[i]<v.back() && k>0){
                    v.pop_back();
                    k--;
                }
                v+=num[i];
            }
        
        while(k--){
        v.pop_back();
        }
        
        int i=0;
        while(i<v.size() && v[i]=='0')
            i++;
        
        v=v.substr(i);
            
        if(v.size()==0)
            return "0";
        return v;
    }
};