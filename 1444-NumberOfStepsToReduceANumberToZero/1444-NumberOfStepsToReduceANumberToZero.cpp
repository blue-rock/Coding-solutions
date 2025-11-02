// Last updated: 11/2/2025, 10:28:23 PM
class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while(num>0)
        {
            if(num%2==0)
            {
                num = num/2;
            }
            else
            {
                num--;
            }
            count++;
        }
        return count;
    }
};