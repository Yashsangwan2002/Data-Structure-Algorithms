class Solution {
public:
    void find(int x,int y,int n,int m,vector<vector<char>>& grid){
        int row[]={1,-1,0,0};
        int col[]={0,0,-1,1};
        grid[x][y]='v';
        for(int i=0;i<4;i++){
            int nx=x+row[i];
            int ny=y+col[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]=='1'){
                find(nx,ny,n,m,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    find(i,j,n,m,grid);
                };
            };
        };
        return ans;
    }
};