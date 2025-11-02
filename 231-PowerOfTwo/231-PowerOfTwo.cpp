// Last updated: 11/2/2025, 10:32:51 PM
class Solution {
public:
    bool isPowerOfTwo(int n) {
       
       return (n>0 and not(n & n-1)) ;  
    }
};