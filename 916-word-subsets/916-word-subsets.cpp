class Solution {
public:
    //this function is used to return  frequency of chars of a string  
    vector<int>counter(string s){
        vector<int>temp(26,0);
        for(auto it:s) temp[it-'a']++;
        return temp;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int>v(26,0);
        for(auto it:words2){
            string s=it;
            vector<int>temp=counter(s);
            for(int i=0;i<26;i++) 
                v[i]=max(v[i], temp[i]);
        }
        
        vector<string>ans;
        
        for(auto it:words1){
            vector<int>temp=counter(it);
            bool flag=true;
            for(int i=0;i<26;i++){
                if(temp[i]<v[i]){flag=false; break;}
            }
            if(flag)ans.push_back(it);
        }
        return ans;
    }
};