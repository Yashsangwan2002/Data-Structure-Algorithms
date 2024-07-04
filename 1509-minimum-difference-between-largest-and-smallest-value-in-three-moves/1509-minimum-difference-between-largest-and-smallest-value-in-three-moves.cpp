class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<5)return 0;
        int first=0;
        int last=nums.size()-1;
        int changes=0;
        while(first<last&&changes<3){
            if(nums[last-1]-nums[first]<nums[last]-nums[first+1])last--;
            else first++;
            changes++;
        };
        return nums[last]-nums[first];
    }
};