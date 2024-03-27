class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        int fast=0;
        int slow=0;
        int product=1;
        while(fast<nums.size()){
            product*=nums[fast];
            while(product>=k&&slow<=fast){
                product/=nums[slow];
                slow++;
            }
            if(product<k)ans+=fast-slow+1  ;
            fast++;
        };
        return ans;
    }
};