// Last updated: 1/3/2026, 1:10:05 PM
1class Solution {
2public:
3    int orangesRotting(vector<vector<int>>& grid) {
4        int minutes = 0;
5        int rottenoranges = 0;
6        int freshoranges = 0;
7        for(int i=0;i<grid.size();i++){
8            for(int j=0;j<grid[0].size();j++){
9                if(grid[i][j]==1){
10                    freshoranges++;
11                }
12                else if(grid[i][j]==2){
13                    rottenoranges++;
14                }
15            }
16        }
17        while(true){
18            if(freshoranges==0){
19                return minutes;
20            }
21            minutes++;
22            markRottenOranges(grid);
23            int newfreshoranges = getFreshOrangesAndRemarkRotten(grid);
24            if(newfreshoranges==freshoranges){
25                return -1;
26            }
27            rottenoranges = rottenoranges + freshoranges - newfreshoranges;
28            freshoranges = newfreshoranges;
29        }
30        return -1;   
31    }
32
33    void markRottenOranges(vector<vector<int>>& grid){
34        for(int i=0;i<grid.size();i++){
35            for(int j=0;j<grid[0].size();j++){
36                if(grid[i][j]==2){
37                    if(i-1>=0 && i-1<grid.size() && j>=0 && j<grid[0].size() &&  grid[i-1][j]==1){
38                        grid[i-1][j]=3;
39                    }
40                    if(i>=0 && i<grid.size() && j-1>=0 && j-1<grid[0].size() && grid[i][j-1]==1){
41                        grid[i][j-1]=3;
42                    }
43                    if(i+1>=0 && i+1<grid.size() && j>=0 && j<grid[0].size() &&  grid[i+1][j]==1){
44                        grid[i+1][j]=3;
45                    }
46                    if(i>=0 && i<grid.size() && j+1>=0 && j+1<grid[0].size() &&  grid[i][j+1]==1){
47                        grid[i][j+1]=3;
48                    }  
49                }
50            }
51        }
52    }
53    int getFreshOrangesAndRemarkRotten(vector<vector<int>>& grid){
54        int freshOran = 0;
55        for(int i=0;i<grid.size();i++){
56            for(int j=0;j<grid[0].size();j++){
57                if(grid[i][j]==3){
58                    grid[i][j]=2;
59                }
60                if(grid[i][j]==1){
61                    freshOran++;
62                }
63            }
64        }
65        return freshOran;
66    }
67};