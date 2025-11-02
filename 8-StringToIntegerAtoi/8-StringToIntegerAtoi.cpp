// Last updated: 11/2/2025, 10:35:51 PM
class Solution {
public:
    int myAtoi(string s) {
        int flag = 0;
        int i = 0;
        int sign = 1; //positive;
        long long num = 0;
        //space check
        for(i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
            {
                break;
            }
        }
        if(s[i]=='-')
        {
            sign = -1;
            i++;
        }
        else if(s[i]=='+')
        {
            i++;
        }
        while(flag==0)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                num = num*10 + (int)(s[i]-'0');
                if(sign*num<INT_MIN)
                {
                    return INT_MIN;
                }
                else if(sign*num>INT_MAX)
                {
                    return INT_MAX;
                }
            }
            else
            {
                flag =1;
            }
            i++;
        }
        num = num*sign;
        if(num<INT_MIN)
        {
            return INT_MIN;
        }
        if(num>INT_MAX)
        {
            return INT_MAX;
        }
        return num;
    }
};