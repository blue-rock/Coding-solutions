// Last updated: 11/2/2025, 10:27:25 PM
class Solution {
public:
    bool isThree(int n) {
        int c = 0;
        for(int i=1;i<=n;i++)
        {
            if(n%i ==0)
            {
                c++;
            }
            if(c>3)
            {
                return false;
            }
        }
        if(c<3)
        {
            return false;
        }
        return true;
    }
};