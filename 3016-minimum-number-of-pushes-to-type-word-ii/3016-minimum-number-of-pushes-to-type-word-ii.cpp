class Solution {
public:
    int minimumPushes(string word) {
        vector<pair<int,char>> pos(26,{0,-1});
        for(int i=0;i<26;i++){pos[i].second=i+'a';};
        for(auto it:word){
            pos[it-'a'].first++;
        };
        sort(pos.begin(),pos.end());
        int n=0;
        int ans=0;
        for(int i=25;i>=0;i--){
            if(pos[i].first!=0){
                n++;
                if(n%8!=0)ans+=(n/8+1)*pos[i].first;
                else ans+=(n/8)*pos[i].first;
            };
        };
        return ans;
    }
};