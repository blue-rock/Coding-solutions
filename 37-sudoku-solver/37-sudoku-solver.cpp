class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(isvalidboard(board,i,j,c))
                        {
                            board[i][j] = c;
                            if(solve(board))
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isvalidboard(vector<vector<char>>& board,int r,int j,char c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][j]==c)
            {
                return false;
            }
            if(board[r][i]==c)
            {
                return false;
            }
            if(board[3*(r/3)+i/3][3*(j/3)+ i%3]==c)
            {
                return false;
            }
        }
        return true;
    }
};