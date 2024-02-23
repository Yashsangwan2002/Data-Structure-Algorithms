class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj (n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> dist(n,INT_MAX);
        queue<pair<pair<int,int>,int>> pq;
        pq.push({{0,0},src});
        dist[src]=0;
        while(!pq.empty()){
            int dis=pq.front().first.first;
            int x=pq.front().first.second;
            int node=pq.front().second;
            pq.pop();
            if(x<=k){
                for(auto it:adj[node]){
                if(dis+it.second<dist[it.first]){
                    dist[it.first]=dis+it.second;
                    pq.push({{dis+it.second,x+1},it.first});
                };
             };
            }

        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};