class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nums;
        for(auto it:nums2)nums[it]++;
        vector<int> ans;
        for(auto it:nums1){
            if(nums.find(it)!=nums.end()&&nums[it]!=0){
                ans.push_back(it);
                nums[it]=0;
            };
        };
        return ans;
    }
};