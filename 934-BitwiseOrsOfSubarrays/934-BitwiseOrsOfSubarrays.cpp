// Last updated: 11/2/2025, 10:29:41 PM
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++)
        {
            st.insert(arr[i]);
            for(int j=i-1;j>=0;j--)
            {
                if((arr[i]|arr[j])==arr[j])
                {
                    break;
                }
                arr[j]|=arr[i]; //update value;
                st.insert(arr[j]);
            }
        }
        return st.size();
    }
};