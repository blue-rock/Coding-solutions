// Last updated: 11/2/2025, 10:28:17 PM
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // v/ector<int>exp(arr.size(),0);
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
           mp[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]*2==arr[i]){
                if(mp[arr[i]]>=2){
                    return true;
                }
            }
            else{
                if(mp.find(arr[i]*2)!=mp.end()){
                    return true;
                }
            }
        }
        return false;
    }
};