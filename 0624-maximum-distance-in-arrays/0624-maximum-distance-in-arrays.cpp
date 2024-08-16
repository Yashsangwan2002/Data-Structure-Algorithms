class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans=INT_MIN;
        pair<int,int> min1;
        pair<int,int> min2;
        int mini=INT_MAX;
        int i=0;
        for(auto it:arrays){
            if(mini>it[0]){
                min1.first=it[0];
                min1.second=i;
                mini=it[0];
            };
            i++;
        };
        i=0;mini=INT_MAX;
        for(auto it:arrays){
            if(mini>it[0]&&i!=min1.second){
                min2.first=it[0];
                min2.second=i;
                mini=it[0];
            };
            i++;
        }
        for(int i=0;i<arrays.size();i++){
            if(i==min1.second){
                ans=max(ans,abs(arrays[i][arrays[i].size()-1]-min2.first));
            }else{
                ans=max(ans,abs(arrays[i][arrays[i].size()-1]-min1.first));
            };
        };
        return ans;
        
    }
};