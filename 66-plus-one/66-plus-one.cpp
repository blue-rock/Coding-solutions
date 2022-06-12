class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n  =digits.size();
        for(int i=n-1;i>=0;i--)
        {
            if(digits[i]==9)
            {
                carry = 1;
                digits[i] = 0;
            }
            else
            {
                digits[i]++;
                carry = 0;
                return digits;
            }
        }
        if(carry==1)
        {
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};