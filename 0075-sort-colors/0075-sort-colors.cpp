class Solution {
public:
    void sortColors(vector<int>& nums) {
        int f=0;
        int l=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0&&f<i){
                nums[i]=nums[f];
                nums[f]=0;
                f++;
                i--;
                continue;
            }else if(nums[i]==2&&i<l){
                nums[i]=nums[l];
                nums[l]=2;
                l--;
                i--;
                continue;
            };
        };
    }
};