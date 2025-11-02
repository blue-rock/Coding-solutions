// Last updated: 11/2/2025, 10:32:53 PM
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    int c1=0;
    int c2=0;
    int n1=0;
    int n2=1;
        
    
    for(auto n: nums){
        if (n1==n){
            c1++;
        }
        else if (n2==n){
            c2++;
        }
        else if (c1==0){
            n1 = n;
            c1 = 1;
        }
        else if (c2 == 0){
            n2 = n;
            c2 = 1;
        }
        else{
            c1--;
            c2--;
        }
    }
    
    c1 = c2 = 0;
    for(auto n: nums){
        if (n==n1)   c1++;
        else if (n==n2)  c2++;
    }
    
    vector<int>v;
    if(c1>nums.size()/3)
    {
        v.push_back(n1);
    }
    if(c2>nums.size()/3)   
    {
        v.push_back(n2);
    }
    return v;
}
};