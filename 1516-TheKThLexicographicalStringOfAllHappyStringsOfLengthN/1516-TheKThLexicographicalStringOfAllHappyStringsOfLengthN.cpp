// Last updated: 11/2/2025, 10:28:13 PM
class Solution {
public:
    void track(int ind,int n,vector<string>&ans,string s){
        if(ind==n){
            ans.push_back(s);
            return;
        }
        for(int i=0;i<3;i++){
            if(s.back()!='a'+i){
                string str=s;
                 str.push_back('a'+i);
                track(ind+1,n,ans,str); 
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string>ans;
        track(0,n,ans,"");
        if(k>ans.size()){
            return "";
        }
        return ans[k-1];
    }
};