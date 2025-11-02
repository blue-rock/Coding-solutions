// Last updated: 11/2/2025, 10:35:48 PM
class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = height.size()-1;
        int low = 0;
        int high = s;
        int ans = 0;
        while(low<high){
            int lowest = min(height[low], height[high]);
            ans = max(ans, lowest*s);
            s--;
            if(height[low]>height[high]){
                high--;
            }
            else{
                low++;
            }
        }
        return ans;
    }
};