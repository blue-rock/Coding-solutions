// Last updated: 11/2/2025, 10:28:32 PM
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>res;
        sort(products.begin(),products.end());
        int l = 0;
        int r = products.size()-1;
        for(int i=0;i<searchWord.length();i++)
        {
            auto c = searchWord[i];
            while(l<=r && (products[l].length()<=i || products[l][i]!=c))
            {
                l++;
            }
            while(l<=r && (products[r].length()<=i || products[r][i]!=c))
            {
                r--;
            }
            int remain = r-l+1;
            vector<string>temp;
            for(int j=0;j<min(3,remain);j++)
            {
                temp.push_back(products[l+j]);
            }
            res.push_back(temp);
        }
        return res;
    }
};