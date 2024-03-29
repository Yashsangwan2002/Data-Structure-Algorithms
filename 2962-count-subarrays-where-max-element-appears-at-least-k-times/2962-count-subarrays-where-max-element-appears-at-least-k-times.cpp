class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=INT_MIN;long long n=nums.size();
        for(auto it:nums)maxi=max(maxi,it);
        long long ans=0;
        int slow=0;
        int fast=0;int freq=0;
        while(fast<n){
            if(nums[fast]==maxi)freq++;
            while(freq>=k&&slow<fast){
                if(nums[slow]==maxi)freq--;
                slow++;
            };
            if(freq<k)ans+=fast-slow+1;
            fast++;
        };
        long long total=n*(n+1)/2;

        return total-ans;
    }
};