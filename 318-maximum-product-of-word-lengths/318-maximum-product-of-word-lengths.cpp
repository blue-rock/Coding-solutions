class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int max_length = 0;
        for(int i=0;i<n;i++)
        {
            // i is a word
            string f_word = words[i];
            for(int j=i+1;j<n;j++)
            {
                string s_word = words[j];
                int flength = f_word.length();
                int slength = s_word.length();
                int flag = 0;
                if((flength*slength)>max_length)
                {
                    for(int f=0;f<flength;f++)
                    {
                        for(int s=0;s<slength;s++)
                        {
                            if(f_word[f]==s_word[s])
                            {
                                f=flength+3;
                                s=slength+3;
                                flag=1;
                            }
                        }
                    }
                    if(flag==0)
                    {
                        max_length = flength*slength;
                    }
                }
            }
        }
        return max_length;
    }
};