class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            ans+=maxi-nums[i];
            maxi++;
        };
        return ans;
    }
};