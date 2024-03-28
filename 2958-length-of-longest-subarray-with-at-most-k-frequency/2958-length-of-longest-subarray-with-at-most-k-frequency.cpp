class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int slow=0;
        int fast=0; int ans=INT_MIN;
        while(fast<nums.size()){
            freq[nums[fast]]++;
                while(freq[nums[fast]]>k){
                    freq[nums[slow]]--;
                    slow++;
                };
                ans=max(ans,fast-slow+1);
                fast++;   
        };
        return ans;
    }
};