class Solution {
public:
    int mod=1000000007;
    int iterate(int ind,int a,int l,int n,vector<vector<vector<int>>>& dp){
        if(ind==n+1)return 1;
        int ans=0;
        if(dp[ind][a][l]!=-1)return dp[ind][a][l];
        if(a<1)ans=(ans+iterate(ind+1,a+1,0,n,dp))%mod;
        if(l<2)ans=(ans+iterate(ind+1,a,l+1,n,dp))%mod;
        ans=(ans+iterate(ind+1,a,0,n,dp))%mod;
        return dp[ind][a][l]=ans;
    }
    int checkRecord(int n) {
       vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(4, -1)));
        return iterate(1,0,0,n,dp);
    }
};