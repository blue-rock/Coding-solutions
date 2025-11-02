// Last updated: 11/2/2025, 10:34:43 PM
class Solution {
public:
    bool res;
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    bool ispresent = check(board,word,i,j,0,visited);
                    if(ispresent){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool check(vector<vector<char>>& board, string word, int r, int c, int idx,vector<vector<int>>& visited){
        if(r<0 || c<0 || r>(board.size()-1) || c>(board[0].size()-1) || visited[r][c]==1
         || idx>(word.length()-1) || word[idx]!=board[r][c]){
            return false;
        }
        if(word[idx]==board[r][c] && (word.length()-1)==idx){
            return true;
        }
        visited[r][c]=1;
        res = check(board,word,r+1,c,idx+1,visited) || check(board,word,r,c+1,idx+1,visited) 
        || check(board,word,r-1,c,idx+1,visited) || check(board,word,r,c-1,idx+1,visited) ;
        visited[r][c] = 0;
        return res;
    }
};