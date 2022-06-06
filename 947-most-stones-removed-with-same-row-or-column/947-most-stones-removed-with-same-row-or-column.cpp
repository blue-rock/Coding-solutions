class UnionFind{
    unordered_map<int,int>parent;
    unordered_map<int,int>rank;
    public:
    int count;
    UnionFind(vector<vector<int>>stones)
    {
        for(vector<int>&stone:stones)
        {
            int row = -(stone[0]+1);
            int col = stone[1] + 1;
            parent[row] = row;
            parent[col] = col;
        }
        count = parent.size();
    }
    int findpar(int x)
    {
        if(parent[x]!=x)
        {
            parent[x] = findpar(parent[x]);
        }
        return parent[x];
    }
    void make_union(int x,int y)
    {
        int p1 = findpar(x);
        int p2 = findpar(y);
        if(p1==p2)
        {
            return;
        }
        count--;
        if(rank[p1]<rank[p2])
        {
            parent[p1] = p2;
        }
        else if(rank[p2]<rank[p1])
        {
            parent[p2] = p1;
        }
        else
        {
            parent[p2] = p1;
            rank[p1] = rank[p2] +1;
        }
    }
};
class Solution {
public:

    int removeStones(vector<vector<int>>& stones) {
        UnionFind uf(stones);
        for(vector<int>&stone:stones)
        {
            int row = -(stone[0]+1);
            int col = stone[1] + 1;
            uf.make_union(row,col);
        }
        return stones.size() - uf.count;
    }
};