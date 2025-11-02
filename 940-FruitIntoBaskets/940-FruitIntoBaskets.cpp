// Last updated: 11/2/2025, 10:29:40 PM
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int first=-1,second=-1,fsi=0,ssi;
        int n=fruits.size();
        int sum=0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(first==-1)
            {
                first=fruits[i];
                fsi=i;
                sum++;
            }
            else if(fruits[i]!=first && second==-1)
            {
                second=fruits[i];
                ssi=i;
                sum++;
            }
            else if(fruits[i]==first || fruits[i]==second)
            {
                if(fruits[i]==first)
                    fsi=i;
                else
                    ssi=i;
                sum++;
            }
            else
            {
                if(fruits[i-1]!=first)
                {
                    first=fruits[i];
                    sum=i-fsi;
                    fsi=i;
                }
                else
                {
                    second=fruits[i];
                    sum=i-ssi;
                    ssi=i;
                }
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};