class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int lastfruit = -1;
        int secondlastfruit = -1;
        int lastfruitcount = 0;
        int currmax = 0;
        int maxv= 0;
        
        for(auto fruit:fruits)
        {
            if(fruit==lastfruit || fruit==secondlastfruit)
            {
                currmax++;
            }
            else
            {
                currmax = lastfruitcount+1;
            }
            if(fruit==lastfruit)
            {
                lastfruitcount++;
            }
            else
            {
                lastfruitcount=1;
            }
            if(fruit!=lastfruit)
            {
                secondlastfruit=lastfruit;
                lastfruit = fruit;
            }
            maxv = max(maxv,currmax);
        }
        return maxv;
    }
};