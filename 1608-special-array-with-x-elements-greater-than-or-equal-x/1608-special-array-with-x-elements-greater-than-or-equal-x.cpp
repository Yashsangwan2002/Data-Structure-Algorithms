class Solution {
public:
      int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
       for(int i=0;i<=nums[n-1];i++){
        int lb = lower_bound(nums.begin(),nums.end(),i)-nums.begin();
        if(n-lb == i) return i;
       } 
       return -1;
    }
};