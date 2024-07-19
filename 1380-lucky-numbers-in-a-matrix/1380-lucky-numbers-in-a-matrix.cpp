class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> maxcol(matrix[0].size(),INT_MIN);
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxcol[i]=max(maxcol[i],matrix[j][i]);
            };
        };
        vector<int> ans;
        for(int i=0;i<m;i++){
            int temp=INT_MAX;
            int ind=0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<temp){
                    ind=j;
                    temp=matrix[i][j];
                };
            };
            if(temp>=maxcol[ind])ans.push_back(temp);
        };
        return ans;
    }
};