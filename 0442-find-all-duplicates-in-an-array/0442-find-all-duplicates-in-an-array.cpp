class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int index=0;
        for(int i=0;i<nums.size();i++){
            index=abs(nums[i])-1;
            if(nums[index]<0){
                ans.push_back(abs(nums[i]));
            }else{
                nums[index]=-nums[index];
            };
        };
        return ans;
    }
};