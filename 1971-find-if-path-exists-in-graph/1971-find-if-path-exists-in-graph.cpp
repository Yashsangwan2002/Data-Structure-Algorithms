class Solution {
public:
    bool find(int curr,vector<vector<int>>& adj,vector<int> vis,int destination){
        if(curr==destination)return true;
        vis[curr]=1;
        for(auto it:adj[curr]){
            if(vis[it]==0){
                if(find(it,adj,vis,destination))return true;
            };
        };
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        };
        return find(source,adj,vis,destination);

    }
};