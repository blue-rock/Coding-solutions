// Last updated: 11/2/2025, 10:27:53 PM
class Solution {
public:
    int minNumberOperations(vector<int>& target) 
    {
          int n = target.size();

          if(n==1)
          {
             return target[0];
          }

          int i=0;
          int j=1;
          int ans=0;

          while(j<n)
          {
               if(target[j]>=target[i])
               {
                  target[i]=target[j];
                  i++;
                  j++;
               }
               else if(target[j]<target[i])
               {
                  ans+=(target[i]-target[j]);
                  target[i]=target[j];
                  i++;
                  j++;
               }
          }

          return ans+target[n-1];
    }
};