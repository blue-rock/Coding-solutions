class Solution {
public:
    int cutOffTree(vector<vector<int>>& f) {
      
        /* Way to move in 4 direction */
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        
        /* keeping a copy of original forest */
        vector<vector<int>> orig(f.begin(),f.end());
        
        vector<int> p;
        
        /* store all the values that are greater than 1 */
        for(int i = 0 ; i < f.size(); i++ )
        {
            for(int j = 0; j < f[0].size(); j++)
            {
                if(f[i][j] > 1 )
                {
                    p.push_back(f[i][j]);
                }
            }
        }
        
        /*sort the element, we will visit each node one by one in this order */
        sort(p.begin(),p.end());
        
        int ans = 0;
        
        int x = 0;  /* x coordinate */
        int y = 0;  /* y coordinate */
        int ans1 = 0; /* steps required to move from point A to point B */
        int vis = 0;  /* Indicate whether it is possible to reach some point or not */
        int flag = 0; /* variable to break out of two loop,as goto is not a right option */
        
        
        /* outer loop will run for all values that needs to be visited. */
        for(int i = 0 ; i < p.size(); i++)
        {
            vis = 0;
            int val = p[i];
           
            queue<pair<int,int>> q;
            q.push({x,y});
            
            /* our standard BFS implementation with just one tweak 
               -> break out of loop when our val is found and move on to next value. 
             */
            while(!q.empty())
            {
                
                if(val == orig[q.front().first][q.front().second])
                {         
                    x = q.front().first;   /* setting up coordinate for next iteration */
                    y = q.front().second;
                    vis = 1;   /* if val is found, vis is made one otherwise we can directly                                      return -1 */
                    break;
                }
               
                ans1++; /* increasing step count for bfs */
                flag = 0;
                int size = q.size();
             
                while(size--)
                {
                    
                    pair<int,int> temp = q.front();
                    q.pop();
                    x = temp.first;
                    y = temp.second;
                   
                    for(int j = 0 ;j < 4; j++)
                    {
                        int newX = x + dx[j];
                        int newY = y + dy[j];
                        
                        if(newX >= 0 && newX < f.size() && newY >= 0 && newY < f[0].size() &&
                          f[newX][newY] >= 1)
                        {
                            if(val == orig[newX][newY])
                            {         
                                vis = 1;    /* if val is found, vis is made one otherwise we                                                   can directly return -1 */
                                x = newX;   /* setting up coordinate for next iteration */
                                y = newY;
                                flag = 1;
                                break;
                            }
                            q.push({newX,newY});
                            f[newX][newY] = 0;/*making it 0 so our bfs will converge quicky */
                        }
                    }
                    if(flag)
                    {
                        break;
                    }
                }
                if(flag)
                    break;
            }
            
            ans = ans + ans1; /* adding to the final result */
            
            /* copying original value to variable for next iterations*/
            flag = 0;
            f = orig;
            ans1 = 0;
            
            if(vis == 0)  /* there is no path to reach a given point , return -1*/
                return -1;
                 
        }
        return ans;
        
    }
};