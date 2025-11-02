// Last updated: 11/2/2025, 10:35:20 PM
class Solution {
public:
    string countAndSay(int n) {
        vector<int>temp;
        vector<int>say;
        say.push_back(1);
        int count = 0;
        int flag= 0;
        for(int j=0;j<n-1;j++)
        {
            int i = 0;
            while(i<say.size())
            {
                int curr = say[i];
                count = 0;
                while(i<say.size() && say[i] == curr)
                {
                    count++;
                    i++;
                }
                temp.push_back(count);
                temp.push_back(curr);
            }
            say = temp;
            temp.clear();
        }
        string str;
        for(int i=0;i<say.size();i++)
        {
            str = str + to_string(say[i]);
        }
        return str;
    }
};
//
// call1:  1
// call2: one 1 - 11
// two 1 -- 21
// one 2 one 1 - 1211
//     one 1 one 2 two 1
//     111221;