class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        if(n==0 || n==2 || n==3)
        {
            return res;
        }
        vector<string> board(n,string(n,'.'));
        findPlaces(board,0);
        return res;
    }
    void findPlaces(vector<string>& board,int row)
    {
        if(row==board.size())
        {
            res.push_back(board);
            return ;
        }
        for(int i=0;i<board.size();i++)
        {
            if(issafe(board,row,i)){
                board[row][i]='Q';
                findPlaces(board,row+1);
                board[row][i]='.';
            }
        }
    }
    
    bool issafe(vector<string> board,int row, int ind)
    {
        for(int i=row;i>=0;i--)
        {
            if(board[i][ind]=='Q')
                return false;
        }
        for(int i=row,j=ind;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
        for(int i=row,j=ind;i>=0&&j<board.size();i--,j++)
        {
            if(board[i][j]=='Q')
                return false;
        }
        return true;
    }
};
//https://www.youtube.com/watch?v=1OkZKjxRokU
