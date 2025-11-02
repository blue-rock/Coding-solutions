// Last updated: 11/2/2025, 10:33:32 PM
class Solution {
public:
    string reverseWords(string line) {
    vector <string> tokens;
    stringstream check1(line);
     
    string intr;
    while(getline(check1, intr, ' '))
    {
        intr.erase(remove(intr.begin(), intr.end(), ' '), intr.end());
        if(!intr.empty())
        {
        tokens.push_back(intr);
        }
    }
    reverse(tokens.begin(),tokens.end());
    string ret;
    for(int i=0;i<tokens.size();i++)
    {
        if(i!=tokens.size()-1)
        {
        ret = ret + tokens[i] + " ";
        }
        else
        {
            ret = ret + tokens[i];
        }
    }
        return ret;
    }
};