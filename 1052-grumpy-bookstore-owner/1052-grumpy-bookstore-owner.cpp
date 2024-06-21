class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans=0;
        for(int i=0;i<grumpy.size();i++){
            if(i<minutes){
                ans+=customers[i];
                continue;
            };
            if(grumpy[i]==0)ans+=customers[i];
        };
        int maxi=ans;
        for(int i=minutes;i<grumpy.size();i++){
            if(grumpy[i]==1){
                ans+=customers[i];
            };
            if(grumpy[i-minutes]==1)ans-=customers[i-minutes];
            maxi=max(maxi,ans);
        };
        return maxi;
    }
};