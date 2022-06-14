class Solution {
public:
    vector<vector<bool>>pacific;
    vector<vector<bool>>atlantic;
    vector<vector<int>>ans;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        if(rows==0)
        {
            return ans;
        }
        int cols = heights[0].size();
        pacific = atlantic = vector<vector<bool>>(rows,vector<bool>(cols,0));
        for(int i=0;i<rows;i++)
        {
            dfs(heights,pacific,i,0);
            dfs(heights,atlantic,i,cols-1);
        }
        for(int i=0;i<cols;i++)
        {
            dfs(heights,pacific,0,i);
            dfs(heights,atlantic,rows-1,i);
        }
        return ans;
    }
    void dfs(vector<vector<int>>& heights,vector<vector<bool>>& visited,int i,int j)
    {
        if(visited[i][j])
        {
            return;
        }
        visited[i][j] = true;
        if(atlantic[i][j] && pacific[i][j])
        {
            vector<int>temp;
            temp.push_back(i);
            temp.push_back(j);
            ans.push_back(temp);
        }
        if(i+1<heights.size() && heights[i+1][j]>=heights[i][j])
        {
            dfs(heights,visited,i+1,j);
        }
        if(i-1>=0 && heights[i-1][j]>=heights[i][j])
        {
            dfs(heights,visited,i-1,j);
        }
        if(j+1<heights[0].size() && heights[i][j+1]>=heights[i][j])
        {
            dfs(heights,visited,i,j+1);
        }
        if(j-1>=0 && heights[i][j-1]>=heights[i][j])
        {
            dfs(heights,visited,i,j-1);
        }
        
    }
};