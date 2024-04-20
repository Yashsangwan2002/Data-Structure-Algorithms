class Solution {
public:
    pair<int,int> first={INT_MAX,INT_MAX};
    pair<int,int> second={INT_MIN,INT_MIN};
    void find(int x,int y,int n,int m,vector<vector<int>>& grid){
        grid[x][y]=2;
        first=min(first,{x,y});
        second=max(second,{x,y});
        int row[]={0,1,0,-1};
        int col[]={1,0,-1,0};
        for(int i=0;i<4;i++){
            int x2=x+row[i];
            int y2=y+col[i];
            if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < m&&grid[x2][y2] == 1) {
                find(x2, y2, n, m, grid);
            };
        };
        return;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
         for(int x=0;x<land.size();x++){
            for(int y=0;y<land[0].size();y++){
                if(land[x][y]==1){
                    first={INT_MAX,INT_MAX};
                    second={INT_MIN,INT_MIN};
                    vector<int> temp(4,0);
                    find(x,y,land.size(),land[0].size(),land);
                    temp[0]=first.first;
                    temp[1]=first.second;
                    temp[2]=second.first;
                    temp[3]=second.second;
                    ans.push_back(temp);
                };
            };
        };
        return ans;
    }
};