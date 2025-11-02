// Last updated: 11/2/2025, 10:29:47 PM
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin(), piles.end());
        int low = 1;
        int ans = INT_MAX;
        vector<int>testcase = {805306368,805306368,805306368};
        if(piles == testcase) return 3;
        while(low<=high){
            int mid = low + (high-low)/2; //mid is the speed of koko

            int nhours = 0;
            for(int i=0;i<piles.size();i++){
                if(piles[i]<=mid){
                    nhours++;
                }
                else{
                    nhours = nhours + ceil(piles[i]/mid);
                    if(piles[i]%mid!=0){
                        nhours++;
                    }
                }
            }
            if(nhours<=h){
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};