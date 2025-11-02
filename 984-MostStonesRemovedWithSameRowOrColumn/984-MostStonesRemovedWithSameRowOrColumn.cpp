// Last updated: 11/2/2025, 10:29:31 PM
class Solution {
public:
    unordered_map<int,int>parent;
    unordered_map<int,int>rank;
    int count = 0;
    int findpar(int x)
    {
        if(parent[x]!=x)
        {
            parent[x] = findpar(parent[x]);
        }
        return parent[x];
    }
    void makeunion(int x,int y)
    {
        int p1 = findpar(x);
        int p2 = findpar(y);
        if(p1==p2)
        {
            return;
        }
        count--;
        if(rank[p1]>rank[p2])
        {
            parent[p2] = p1;
        }
        else if(rank[p2]<rank[p1])
        {
            parent[p1] = p2;
        }
        else
        {
            parent[p1] = p2;
            rank[p2] = rank[p1] + 1; 
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        for(auto stone:stones)
        {
            int row = -(stone[0]+1);
            int col = stone[1]+1;
            parent[row] = row;
            parent[col] = col;
        }
        count = parent.size();
        for(auto stone:stones)
        {
            int row = -(stone[0]+1);
            int col = stone[1]+1;
            makeunion(row,col);
        }
        return stones.size() - count;
    }
};