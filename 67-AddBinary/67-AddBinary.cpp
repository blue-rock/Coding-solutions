// Last updated: 11/2/2025, 10:34:52 PM
class Solution {
public:
    string addBinary(string a, string b) {
        string ret = "";
        int l1 = a.length()-1;
        int l2 = b.length()-1;
        int carry = 0;
        while(l1>=0 || l2>=0 || carry!=0)
        {
            if (l1 >= 0) {
                carry += a[l1]=='0'?0:1;
                l1--;
            }
            if(l2>=0)
            {
                carry += b[l2]=='0'?0:1;
                l2--;
            }
            ret = ((carry%2)==0?"0":"1") + ret;
            carry /= 2;
        }
        return ret;
        
        
    }
};