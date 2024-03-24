class Solution {
public:
    bool find(int course,  vector<vector<int>>& adj, vector<int>& visited,vector<int>& pathvis){
        if (visited[course] == 1) return false;
        visited[course]=1;
        pathvis[course]=1;
        for(auto it:adj[course]){  
            if(visited[it]==0){
                if(find(it,adj,visited,pathvis)==false)return false;
            }else if(pathvis[it]==1)return false;   
        };
        pathvis[course]=0;
        return true;
    };
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        };
        vector<int> visited(numCourses,0);
        
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                if(!find(i,adj,visited))return false;
            };
        };
        return true;
    }
};