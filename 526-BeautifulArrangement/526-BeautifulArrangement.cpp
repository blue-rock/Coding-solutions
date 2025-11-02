// Last updated: 11/2/2025, 10:31:16 PM
class Solution {
public:
    int countArrangement(int n) {
        vector<bool>visited(n+1,false);
        int count =0;
        calc(n,1,visited,count);
        return count;
    }
    void calc(int n,int pos,vector<bool>& visited,int& count)
    {
        if(pos>n)
        {
            count++;
        }
        for(int i=1;i<=n;i++)
        {
            if(!visited[i] && (pos%i==0 || i%pos==0))
            {
                visited[i]=true;
                calc(n,pos+1,visited,count);
                visited[i]=false;
            }
        }
    }
};