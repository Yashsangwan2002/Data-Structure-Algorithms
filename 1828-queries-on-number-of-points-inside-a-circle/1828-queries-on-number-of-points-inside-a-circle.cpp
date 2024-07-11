class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int temp=0;
                for(auto it:points){
                    int dx = queries[i][0] - it[0];
                    int dy = queries[i][1] - it[1];
                    int distanceSquared = dx * dx + dy * dy;
                if (distanceSquared <= queries[i][2] * queries[i][2]) {
                    temp++;
                }
                };
            ans.push_back(temp);
        }
        return ans;
    }
};