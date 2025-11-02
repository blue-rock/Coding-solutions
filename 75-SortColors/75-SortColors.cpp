// Last updated: 11/2/2025, 10:34:47 PM
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a = 0;
        int b = 0;
        int c= 0 ;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                a++;
            }
            if(nums[i]==1)
            {
                b++;
            }
            if(nums[i]==2)
            {
                c++;
            }
        }
        int j=0;
        for(int i=0;i<a;i++)
        {
            nums[j] = 0;
            j++;
        }
        for(int i=0;i<b;i++)
        {
            nums[j] = 1;
            j++;
        }
        for(int i=0;i<c;i++)
        {
            nums[j] = 2;
            j++;
        }
    }
};