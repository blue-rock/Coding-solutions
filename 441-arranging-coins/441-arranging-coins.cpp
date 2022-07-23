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