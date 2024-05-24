class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            int temp=0;
            for(auto it:m){
                if(abs(nums[i]-it.first)==k)temp+=it.second;
            };
            ans+=pow(2,i-temp);
        };
        return ans;
    }
};