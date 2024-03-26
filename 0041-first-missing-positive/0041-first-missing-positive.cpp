class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int maxi=INT_MIN;unordered_set<int> s;
        for(auto it:nums){
            maxi=max(it,maxi);
            if(it>0)s.insert(it);
        }
        if(maxi<1)return 1;
        for(int i=1;i<=maxi;i++){
            if(s.find(i)==s.end())return i;
        };
        return maxi+1;
    }
};