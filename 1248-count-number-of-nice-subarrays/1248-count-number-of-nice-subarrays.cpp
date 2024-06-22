class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)nums[i]=0;
            else nums[i]=1;
        }
        map<int,int>m;int sum=0;int count=0;
        for(auto it:nums){
            sum+=it;
            if(sum==k)count++;
            if(m[sum-k])count+=m[sum-k];
            m[sum]++;
        }
        return count;
        
    }
};