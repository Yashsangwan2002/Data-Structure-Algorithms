class Solution {
public:
    int maxDepth(string s) {
        int ans=INT_MIN;int count=0;
        for(auto it:s){
            if(it=='('){
                count++;
                ans=max(ans,count);
            }else if(it==')')count--;
        };
        return ans==INT_MIN?0:ans;
    }
};