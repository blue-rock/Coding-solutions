// Last updated: 11/9/2025, 8:53:54 PM
class Solution {
public:
    int countOperations(int num1, int num2) {
        int ops = 0;
        while(num1!=0 && num2!=0){
            if(num1>=num2){
                num1 = num1 - num2;
            }
            else{
                num2 = num2 - num1;
            }
            ops++;
        }
        return ops;
    }
};