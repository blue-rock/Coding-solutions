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