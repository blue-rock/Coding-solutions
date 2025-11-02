// Last updated: 11/2/2025, 10:27:17 PM
class Solution {
public:

void markVisitedNodes(int m, int n, vector<vector<int>>& area, int dir){
            int dRow[] = {-1, 0, 1, 0};
            int dCol[] = {0, 1, 0, -1};
        if(n>=area[0].size() || m>=area.size() || m<0 || n<0 || area[m][n]==2 || area[m][n]==1)
        {
            return;
        }
        area[m][n] = 3; //guarded
        markVisitedNodes(m + dRow[dir], n + dCol[dir], area, dir);
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>area(m,vector<int>(n,0));
                    int dRow[] = {-1, 0, 1, 0};
            int dCol[] = {0, 1, 0, -1};
        int ans = 0;
        //mark guards
        for(int i=0;i<guards.size();i++){
            area[guards[i][0]][guards[i][1]] = 1;
        }

        //mark walls
        for(int i=0;i<walls.size();i++){
            area[walls[i][0]][walls[i][1]] = 2;
        }

        //iterate - if guard found - dfs and mark the nodes as visited until there's a wall or index is out of bound;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(area[i][j]==1){
                    for(int k=0;k<4;k++){
                        markVisitedNodes(i + dRow[k], j + dCol[k], area, k);
                    }     
                }
            }
        }
        

        //check uncaptured nodes (0 values)
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(area[i][j]!=1 && area[i][j]!=2 && area[i][j]!=3){
                    ans++;
                }
            }
        }

        //return
        return ans;
    }

    
};