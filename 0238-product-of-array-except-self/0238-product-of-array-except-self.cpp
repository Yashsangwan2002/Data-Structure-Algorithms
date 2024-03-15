class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>pref(nums.size(),1);pref[0]=nums[0];
        vector<int>suf(nums.size(),1);suf[nums.size()-1]=nums[nums.size()-1];
        for(int i=1;i<nums.size();i++)pref[i]=pref[i-1]*nums[i];
        for(int i=nums.size()-2;i>=0;i--)suf[i]=suf[i+1]*nums[i];
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i>0&&i<nums.size()-1)ans[i]=pref[i-1]*suf[i+1];
            if(i==0)ans[i]=suf[i+1];
            if(i==nums.size()-1)ans[i]=pref[i-1];
        }
        return ans;
         
    }
};