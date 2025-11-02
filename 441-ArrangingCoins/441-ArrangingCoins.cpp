// Last updated: 11/2/2025, 10:31:45 PM
class Solution {
public:
    int arrangeCoins(int n) {
       int itr = 1;
        while (1)
        {
           n -= itr ;
            if (n < 0)
            {
                break ;
            }
            itr ++ ;
        }
        
        return itr -1;
    }
};