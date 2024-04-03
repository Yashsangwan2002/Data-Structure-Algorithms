class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int prev=0;int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>=target&&prev<=i){
                ans=min(ans,i-prev+1);
                sum-=nums[prev];
                prev++;
            };
        };
        return ans==INT_MAX?0:ans;
    }
};