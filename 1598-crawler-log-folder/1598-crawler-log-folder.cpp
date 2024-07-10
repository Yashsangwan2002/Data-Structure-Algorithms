class Solution {
public:
    int minOperations(vector<string>& logs) {
        int curr =0;
        for(auto it:logs){
            if(it=="./")continue;
            if(it=="../"&&curr<=0)continue;
            if(it=="../")curr--;
            else curr++;
        };
        return curr;
    }
};