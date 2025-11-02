// Last updated: 11/2/2025, 10:31:22 PM
class Solution {
public:
    string convertToBase7(int num) {
        if(num<0)
        {
            return "-" + convertToBase7(-num);
        }
        if(num<7)
        {
            return to_string(num);
        }
        return convertToBase7(num/7) + to_string(num%7);
    }
};