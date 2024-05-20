class Solution {
public:
    int iterate(int ind,int sum,vector<int>& nums){
        if(ind==nums.size())return sum;
        int notake=iterate(ind+1,sum,nums);
        int take=iterate(ind+1,sum^nums[ind],nums);
        return take+notake;
    }
    int subsetXORSum(vector<int>& nums) {
        return iterate(0,0,nums);
    }
};