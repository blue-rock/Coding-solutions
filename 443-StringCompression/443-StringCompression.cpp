// Last updated: 11/2/2025, 10:31:44 PM
class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> ret;
        if(chars.size()==0)
        {
            return 0;
        }
        if(chars.size()==1)
        {
            return 1;
        }
        for(int i=0;i<chars.size();i++)
        {
            char curr = chars[i];
            int s = 1;
            while(i+1<chars.size() && chars[i+1]==curr )
            {
                s++;
                i++;
            }
            ret.push_back(curr);
            if(s>1)
            {
                string z=to_string(s);
					for(auto y: z){
						ret.push_back(y);
                    }

            }
            
        }
        chars = ret;
        return ret.size();
    }
};