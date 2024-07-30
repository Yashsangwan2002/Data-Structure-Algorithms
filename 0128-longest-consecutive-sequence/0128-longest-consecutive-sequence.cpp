class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int max=0;
        int curr=0;
        int last=0;
        sort(nums.begin(),nums.end());
        unique(nums.begin(),nums.end());
        for(curr=0;curr<n-1;curr++){
             if(nums[curr+1]==nums[curr]+1||curr==n-1){
                 if(curr+2-last>max){
                    max=(curr-last)+2;
                };
               continue;
            }else{
                last=curr+1;
            };
        };
        if(n==2&&nums[1]==nums[0]+1){
            max=2;

        }
        if(n!=0&&max==0){
            max=1;
        }
        return max;

    }
};