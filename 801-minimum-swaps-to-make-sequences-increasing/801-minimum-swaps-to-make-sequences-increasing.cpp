class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        vector<int>swap(n,1);
        vector<int>noswap(n,0);
        for(int i=1;i<n;i++)
        {
            swap[i] = noswap[i] = n;
            if(nums1[i-1]<nums1[i] && nums2[i-1]<nums2[i])
            {
                noswap[i] = noswap[i-1]; 
                swap[i] = swap[i-1] + 1;
            }
            if(nums1[i-1]<nums2[i] && nums1[i]>nums2[i-1])
            {
                swap[i] = min(swap[i],noswap[i-1]+1);
                noswap[i] = min(noswap[i],swap[i-1]);
            }
        }
        return min(swap[n-1],noswap[n-1]);
    }
};