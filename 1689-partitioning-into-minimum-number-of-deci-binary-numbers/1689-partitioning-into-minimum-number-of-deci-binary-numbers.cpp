class Solution {
public:
    int minPartitions(string n) {
        int maxv = 0;
        for(int i=0;i<n.length();i++)
        {
            maxv = max(n[i] - '0',maxv); 
        }
        return maxv;
    }
};