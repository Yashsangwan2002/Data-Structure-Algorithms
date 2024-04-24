
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
     {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0), ans; 
        for(auto &e : edges)
        {   
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        queue<int> q;
        for(int i=0; i<n;i++)
        {
            if(indegree[i]==1) q.push(i), indegree[i]--; 
        } 
        while(!q.empty())
        {
            int s = q.size();
            ans.clear();
            for(int i=0; i<s;i++)
            {
                int curr = q.front(); q.pop();
                ans.push_back(curr);
                for(auto child : graph[curr])
                { 
                    indegree[child]--;
                    if(indegree[child]==1) q.push(child);   
                }
            }
        }
        if(n==1) ans.push_back(0);
        return ans; 
    }
};

// class Solution {
// public:
//     int dfs(int node ,vector<vector<int>>& adj,vector<int>& vis){
//         vis[node]=1;
//         int ans=0;
//         for(auto it:adj[node]){
//             if(vis[it]==-1){
//                 ans=max(ans,1+dfs(it,adj,vis));
//             };
//         };
//         return ans;
//     }
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//         vector<int> heights(n);
//         vector<vector<int>> adj(n);
//         for(auto it:edges){
//             adj[it[0]].push_back(it[1]);
//             adj[it[1]].push_back(it[0]);
//             };
//         for(int i=0;i<n;i++){
//             vector<int> vis(n,-1);
//             heights[i]=dfs(i,adj,vis);
//         };
//         int ans=*min_element(heights.begin(),heights.end());
//         vector<int> final;
//         for(int i=0;i<n;i++){
//             if(heights[i]==ans)final.push_back(i);
//         };
//         return final;

//     }
    
// };