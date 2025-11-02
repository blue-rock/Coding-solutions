// Last updated: 11/2/2025, 10:33:12 PM
class Solution {
    public int numIslands(char[][] grid) {
        Integer rows = grid.length;
        Integer cols = grid[0].length;
        Queue<Map.Entry<Integer, Integer>> q = new LinkedList<>();
        Integer numIslands = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]=='1'){
                    q.add(Map.entry(i,j));
                    grid[i][j] = '0';
                    while(!q.isEmpty()){
                        Map.Entry<Integer, Integer> topEntry = q.poll();
                        Integer currrow = topEntry.getKey();
                        Integer currcol = topEntry.getValue();
                        
                        if(currrow-1>=0 && currrow-1<rows && grid[currrow-1][currcol]=='1'){
                            q.add(Map.entry(currrow-1, currcol));
                            grid[currrow-1][currcol] = '0';
                        }
                        if(currrow+1>=0 && currrow+1<rows && grid[currrow+1][currcol]=='1'){
                            q.add(Map.entry(currrow+1, currcol));
                            grid[currrow+1][currcol] = '0';
                        }
                        if(currcol-1>=0 && currcol-1<cols && grid[currrow][currcol-1]=='1'){
                            q.add(Map.entry(currrow, currcol-1));
                            grid[currrow][currcol-1] = '0';
                        }
                        if(currcol+1>=0 && currcol+1<cols && grid[currrow][currcol+1]=='1'){
                            q.add(Map.entry(currrow, currcol+1));
                            grid[currrow][currcol+1] = '0';
                        }
                    }
                    numIslands++;
                }
            }
        }
        return numIslands;
    }
}

/*
bfs
take one element - if it is one - push it to queue
add adjacent neigbours to queue
iterate while queue is not empty
*/