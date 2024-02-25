class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int f=0;
        int ans=0;
        int n=nums.size();
        for(int l=0;l<n;l++){
            if(nums[l]-nums[f]>k){
                ans++;
                f=l;
            };
        };
        return ans+1;
    }
};