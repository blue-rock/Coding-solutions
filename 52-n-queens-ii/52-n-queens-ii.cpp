class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string>>numways;
        string st = "";
        for(int i=0;i<n;i++)
        {
            st = st +'.';
        }
        vector<string>board(n,st);
        findnum(board,numways,0);
        return numways.size();
    }
    void findnum(vector<string>&board,vector<vector<string>>& numways,int row)
    {
        if(board.size()==0)
        {
            return;
        }
        if(row==board.size())
        {
            numways.push_back(board);
            return;
        }
        for(int i=0;i<board[0].size();i++)
        {
            if(issafe(board,row,i)){
                board[row][i] = 'Q';
                findnum(board,numways,row+1);
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