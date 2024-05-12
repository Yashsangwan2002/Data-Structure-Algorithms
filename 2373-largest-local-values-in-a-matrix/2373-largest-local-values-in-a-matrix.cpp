class Solution {
public:
    int find(int x,int y,int n,vector<vector<int>>& grid){
        int maxi=INT_MIN;
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                maxi=max(maxi,grid[i][j]);
            };
        };
        return maxi;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> v(grid.size()-2,vector<int>(grid.size()-2,0));
        int n=grid.size();
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++ ){
                v[i][j]=find(i,j,n,grid);
            }
        }
        return v;
    }
};