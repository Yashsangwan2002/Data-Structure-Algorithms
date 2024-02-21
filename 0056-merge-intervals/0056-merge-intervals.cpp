class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        auto it=intervals[0];
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>it[1]){
                ans.push_back(it);
                it=intervals[i];
                continue;
            };
            if(intervals[i][0]<=it[1]&&intervals[i][0]>=it[0]){
                if(intervals[i][1]>=it[1]){
                    it={it[0],intervals[i][1]};
                    continue;
                }else{
                    continue;
                }
            }
        };
        ans.push_back(it);
        return ans;
    }
};