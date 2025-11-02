// Last updated: 11/2/2025, 10:35:56 PM
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if(nums1.size()>nums2.size()){
			vector<int> temp=nums1;
			nums1=nums2;
			nums2=temp;
		}

		int size=nums1.size()+nums2.size();
		double ans=-1;
		int setSize=(size+1)/2;
		int low=0,high=nums1.size();
		while(low<=high){
			int mid=(low+high)>>1;
			int startPoint2=setSize-mid;
			int leftMax1=(mid==0)?INT_MIN:nums1[mid-1];
			int rightMin1=(mid==nums1.size())?INT_MAX:nums1[mid];
			int leftMax2=(startPoint2==0)?INT_MIN:nums2[startPoint2-1];
			int rightMin2=(startPoint2==nums2.size())?INT_MAX:nums2[startPoint2];

			if(leftMax1<=rightMin2 and leftMax2<=rightMin1){
				if(size%2==0){//even elements
					ans=(max(leftMax1,leftMax2)+min(rightMin1,rightMin2))/2.0;
				}
				else{
					ans=max(leftMax1,leftMax2);
				}
				break;
			}
			else if(leftMax1>rightMin2){
				high=mid-1;
			}
			else{
				low=mid+1;
			}
		}

		return ans;
	}
};