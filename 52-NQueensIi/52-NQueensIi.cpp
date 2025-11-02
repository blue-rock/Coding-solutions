// Last updated: 11/2/2025, 10:35:07 PM
class Solution {
public:
    vector<vector<string>> res;
    int totalNQueens(int n) {
        if(n==0 || n==2 || n==3)
        {
            return 0;
        }
        vector<string> board(n,string(n,'.'));
        findPlaces(board,0);
        return res.size();
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