class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int ans=-1;int x=0;
        for(int i=0;i<nums1.size();i++){
            if(x>=nums2.size())return ans;
            if(nums1[i]==nums2[x]){
               return nums1[i];
            };
            if(nums1[i]>nums2[x]){
                i--;
                x++;
            }

        };
        return ans;
    }
};