class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> m(n,0);
        for(auto it:roads){
            m[it[0]]++;
            m[it[1]]++;
        };
        long long ans=0;
        sort(m.begin(),m.end());
        n=1;
        for(auto it:m){
            ans+=n*it;
            n++;
        };
        return ans;
    }
};