// Last updated: 11/2/2025, 10:34:36 PM
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<m+n;i++)
        {
            if(i==m)
            {
                for(int j=0;j<n;j++)
                {
                    nums1[i] = nums2[j];
                    i++;
                }
            }
        }
        sort(nums1.begin(),nums1.end());
    }
};