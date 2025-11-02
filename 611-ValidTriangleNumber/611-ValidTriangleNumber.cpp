// Last updated: 11/2/2025, 10:31:05 PM
class Solution {
public:
    int triangleNumber(vector<int>& v) {
        sort(v.begin(),v.end());
        int return_val=0;
        for(int i=v.size()-1;i>=1;i--)
        {
            //set i at the end
            //left at the origin and right at a step behind i
            int left=0; int right=i-1;
            //check for all the triplets with i as constant

            while(left<right){
                if(v[left]+v[right]>v[i]){
                    return_val = return_val + right - left; 
                    right--; 
                }
                else{
                    left++;
                }
            }
        }
        return return_val;
    }
};