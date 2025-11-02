// Last updated: 11/2/2025, 10:33:14 PM
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n>0)
        {
            n = n&(n-1);
            count++;
        }
        return count;
    }
};