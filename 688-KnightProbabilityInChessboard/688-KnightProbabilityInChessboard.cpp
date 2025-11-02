// Last updated: 11/2/2025, 10:30:42 PM
class Solution {
public:
    bool valid(int i,int j, int n){
    if(i>=0 and j>=0 and i<n and j<n){
        return true;
    }
    return false;
}

double findProb(int n,int x, int y, int moves){
    double now[n][n], next[n][n];memset(now,0,sizeof(now));
    now[x][y] = 1.0;memset(next,0,sizeof(next));
    for(int move=0;move<moves;move++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(now[i][j] > 0.0){
                    if(valid(i-2,j+1,n)){
                        next[i-2][j+1] += (now[i][j] / 8.0);
                    }
                    if(valid(i-2,j-1,n)){
                        next[i-2][j-1] += (now[i][j] / 8.0);
                    }
                    if(valid(i+2,j+1,n)){
                        next[i+2][j+1] += (now[i][j] / 8.0);
                    }
                    if(valid(i+2,j-1,n)){
                        next[i+2][j-1] += (now[i][j] / 8.0);
                    }
                    if(valid(i-1,j+2,n)){
                        next[i-1][j+2] += (now[i][j] / 8.0);
                    }
                    if(valid(i-1,j-2,n)){
                        next[i-1][j-2] += (now[i][j] / 8.0);
                    }
                    if(valid(i+1,j+2,n)){
                        next[i+1][j+2] += (now[i][j] / 8.0);
                    }
                    if(valid(i+1,j-2,n)){
                        next[i+1][j-2] += (now[i][j] / 8.0);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                now[i][j] = next[i][j];
                next[i][j] = 0.0;
            }
        }
    }
    double ans = 0.0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans+=now[i][j];
        }
    }
    return ans ;
}

double knightProbability(int n, int k, int row, int column) {
    return findProb(n,row,column,k);
}
};