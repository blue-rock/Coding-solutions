class Solution {
public:
    int huha(vector<int>&a,vector<int>&b,int num)
    {
        int topcount = 0;
        int botcount = 0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=num && b[i]!=num)
            {
                return -1;
            }
            if(a[i]!=num)
            {
                botcount++;
            }
            if(b[i]!=num)
            {
                topcount++;
            }
        }
        return min(topcount,botcount);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
       int f1 = huha(tops,bottoms,tops[0]);
        int f2 = huha(tops,bottoms,bottoms[0]);
        
        return min(f1,f2)>0?min(f1,f2):max(f1,f2);
    }
};