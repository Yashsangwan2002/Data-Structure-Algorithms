class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       set<int> s;
       for(auto it:nums)s.insert(it);
       int ans=INT_MIN;
       int curr=0;
       int last=0;
       for(auto it:s){
            if(curr==0||last==it-1){
                curr++;
                ans=max(ans,curr);
                last=it;
            }else{
                ans=max(ans,curr);
                curr=1;
                last=it;
            };
       }  ;
       if(ans==INT_MIN)return 0;
       return ans;
    }
};