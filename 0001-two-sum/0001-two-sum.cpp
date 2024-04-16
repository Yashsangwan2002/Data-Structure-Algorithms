class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        bool l=false;
        vector<int> v(2);
        for(int i=0;i<n;i++){
            for(int y=i+1;y<n;y++){
                if(nums[i]+nums[y]==target){
                    v[0]=i;
                    v[1]=y;
                    break;
                    return v;
                    l=true;
                };
            };
            if(l){break;}
        };
       return v;

    }
};