class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odd=0;
        for(auto it:arr){
            if(odd==3)return true;
            if(it%2==1)odd++;
            else odd=0;
        };
        return odd>=3?true:false;
    }
};