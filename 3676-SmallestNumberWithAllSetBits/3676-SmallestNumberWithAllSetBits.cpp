// Last updated: 11/2/2025, 10:26:57 PM
class Solution {
public:
    int smallestNumber(int n) {
        //1 bit numbers formulae - n*2+1 (n=0/1 for base- then we take previ numbers for formuala)
        int num = 1;
        while(num<n){
            num = num*2+1;
        }
        return num;
    }
};