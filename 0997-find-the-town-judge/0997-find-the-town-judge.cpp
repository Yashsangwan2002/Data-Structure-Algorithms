class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> to(n+1);
        vector<vector<int>> from(n+1);
        for(auto it: trust){
            to[it[0]].push_back(it[1]);
            from[it[1]].push_back(it[0]);
        };
        for(int i=1;i<n+1;i++){
            if(from[i].size()==n-1&&to[i].size()==0)return i;
        }
        return -1;
    }
};