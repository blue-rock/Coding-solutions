// Last updated: 11/2/2025, 10:35:16 PM
class Solution {
public:
    int trap(vector<int>& height) {
        int s = height.size();
        vector<int>maxleft(s,0);
        vector<int>maxright(s,0);
        int trappedWater = 0;

        if(s<=2){
            return trappedWater;
        }
        for(int i=1;i<s;i++){
            maxleft[i] = max(maxleft[i-1],height[i-1]);
        }

        for(int i=s-2;i>=0;i--){
            maxright[i] = max(maxright[i+1], height[i+1]);
        }

        for(int i=0;i<s-1;i++){
            if((min(maxleft[i],maxright[i]) - height[i])>0){
                trappedWater = trappedWater + min(maxleft[i],maxright[i]) - height[i];
            }
        }
        return trappedWater;
    }
};