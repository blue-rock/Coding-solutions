class Solution {
public:
	bool canThreePartsEqualSum(vector<int>& arr) {
		int sum=0;
		sum = accumulate(arr.begin(),arr.end(),0);
		if(sum%3!=0)
        {
            return false;
        }
		int currsum=0,count=0;
		for(int i=0;i<arr.size();i++){
			currsum+=arr[i];
			if(currsum==sum/3){
				count++;
				currsum=0;
			}
		} 
		return count>=3;
	}
};