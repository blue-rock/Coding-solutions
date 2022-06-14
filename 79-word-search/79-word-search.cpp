class Solution {
public:
    int res;
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>>visited(rows,vector<int>(cols,0));
        res = 0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(findans(board,0,i,j,word,visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool findans(vector<vector<char>>&board,int i,int row,int col,string& word,vector<vector<int>>&visited)
    {
        if(i==word.length())
        {
            return true;
        }
        if(row<0||col<0||row>=board.size()||col>=board[0].size() || word[i]!=board[row][col])
        {
            return false;
        }
        if(visited[row][col])
        {
            return false;
        }
        visited[row][col]=1;
        res = findans(board,i+1,row+1,col,word,visited) || findans(board,i+1,row-1,col,word,visited) || findans(board,i+1,row,col+1,word,visited) || findans(board,i+1,row,col-1,word,visited);
        visited[row][col]=0;
        return res;
    }
};