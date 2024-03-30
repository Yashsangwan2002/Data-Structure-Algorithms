class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return finder(k,nums)-finder(k-1,nums);
    }
    int finder(int k,vector<int>&nums){
        int first=0;
        int ans=0;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(!m[nums[i]]++)k--;
            while(k<0){
                if(!--m[nums[first]])k++;
                first++;
            };
            ans+=i-first+1;
        };
        return ans;
    }
};