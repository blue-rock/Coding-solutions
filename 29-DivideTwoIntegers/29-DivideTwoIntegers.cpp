// Last updated: 11/2/2025, 10:35:30 PM
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1)
        {
            return INT_MAX;
        }
        return dividend/divisor;
        // 10 - 3 - 3.33
    }
};