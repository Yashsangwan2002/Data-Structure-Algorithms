class Solution {
public:
    void ans(vector<vector<int>> &v1,int i,vector<int> &nums,int n,vector<int>v2){
        if(i==n){
            v1.push_back(v2);
            return;
        }
        v2.push_back(nums[i]);
        ans(v1,i+1,nums,n,v2);
        v2.pop_back();
        ans(v1,i+1,nums,n,v2);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v1;
        vector<int>v2;int i=0;int n=nums.size();
        ans(v1,i,nums,n,v2);
        return v1;        
    }
};