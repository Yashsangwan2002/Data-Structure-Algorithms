class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        queue<int> q;
        for(int i=0;i<deck.size();i++)q.push(i);
        int i=0;
        vector<int> ans(deck.size(),0);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            ans[it]=deck[i];
            i++;
            auto temp=q.front();
            q.pop();
            q.push(temp);
        };
        return ans;
    }
};