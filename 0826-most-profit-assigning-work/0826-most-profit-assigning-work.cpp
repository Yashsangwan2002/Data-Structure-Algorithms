class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        unordered_map<int,int> prof;
        for(int i=0;i<profit.size();i++){
            prof[difficulty[i]]=profit[i];
        };
        sort(difficulty.begin(),difficulty.end());
        sort(worker.begin(),worker.end());
        int maxi=0;
        int ptr=0;
        int ans=0;
        for(auto it:worker){
            while(ptr<difficulty.size()&&difficulty[ptr]<=it){
                maxi=max(maxi,prof[difficulty[ptr]]);
                ptr++;
            };
            ans+=maxi;
        }
        return ans;
    }
};