// Last updated: 11/2/2025, 10:31:59 PM
class Solution {
public:
    
     vector<double> res;
     map<string,vector<pair<string,double>>> adj;  
    void find(string x,string y,map<string,int> &vis,double rs)
    {  
        vis[x]=1;
        if(x==y){
          res.push_back(rs);return;
        }
        for(int i=0;i<adj[x].size();i++)
        {  
            string p=adj[x][i].first;
           
            if( vis.count(p)==0)
            {    
                find(p,y,vis,rs*adj[x][i].second);
            }
        }
         
        return;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(equations.size()==0) return res;
        if(equations[0].size()==0) return res;
        
         
        
        for(int i=0;i<equations.size();i++)
        {   
            string x=equations[i][0],y=equations[i][1]; 
            double val=values[i]; 
            adj[x].push_back({y,val});
            adj[y].push_back({x,double(1)/val});
        }
       
         
        for(int i=0;i<queries.size();i++) 
        {   
            string x=queries[i][0],y=queries[i][1];
            if(adj.count(x)==0||adj.count(y)==0) 
             {
                res.push_back(double(-1));continue; 
             }
             map <string,int> vis;
             find(x,y,vis,double(1)*(1.0));
             if(res.size()!=i+1) res.push_back(double(-1));
            
        }
        return res;
        
    }
};