class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>freq;
        vector<int>freq2;
        for(int i=0;i<words.size();i++)
        {
            string curr = words[i];
            sort(curr.begin(),curr.end());
            char scar = curr[0];
            int k=0;
            while(curr[k]==scar && k<curr.length())
            {
                k++;
            }
            freq.push_back(k);
        }
        sort(freq.begin(),freq.end());
        reverse(freq.begin(),freq.end());
        for(int i=0;i<queries.size();i++)
        {
            string curr = queries[i];
            sort(curr.begin(),curr.end());
            char scar = curr[0];
            int k=0;
            while(curr[k]==scar && k<curr.length())
            {
                k++;
            }
            freq2.push_back(k);
        }
        vector<int>temp;
        for(int i=0;i<queries.size();i++)
        {
            int h = 0;
            int count = 0;
            while(h<freq.size() && freq[h]>freq2[i])
            {
                h++;
                count++;
            }
            temp.push_back(count);
        }
        return temp;
    }
};