// Last updated: 11/2/2025, 10:33:15 PM
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        
        for (int i = 0; i < 32; i++) {
            res <<= 1;
            res += n % 2;
            n >>= 1;
        }
        
        return res;
    }
};