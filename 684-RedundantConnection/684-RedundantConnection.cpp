// Last updated: 11/2/2025, 10:30:44 PM
class Solution {
public:
        vector<int> rank;
        vector<int> parent;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        rank.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        for(int i=0;i<n;i++){
            if(!makeUnion(edges[i][0], edges[i][1])){
                return {edges[i][0], edges[i][1]};
            }
        }
        return {-1,-1};

    }

    bool makeUnion(int node1, int node2){
        int parentOfNode1 = findpar(node1);
        int parentOfNode2 = findpar(node2);

        if(parentOfNode1 == parentOfNode2){
            return false;
        }
        if(rank[parentOfNode1]>rank[parentOfNode2]){
            parent[parentOfNode2] = parent[parentOfNode1];
        }
        else if(rank[parentOfNode2]> rank[parentOfNode1]){
            parent[parentOfNode1] = parent[parentOfNode2];
        }
        else{
            parent[parentOfNode1] = parent[parentOfNode2];
            rank[parentOfNode2]++;
        }
        return true;
    }

    int findpar(int node){
        if(parent[node]==node){
            return node;
        }
        parent[node] = findpar(parent[node]);
        return parent[node];
    }
};