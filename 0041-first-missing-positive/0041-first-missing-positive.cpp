class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // int maxi=INT_MIN;unordered_set<int> s;
        // for(auto it:nums){
        //     maxi=max(it,maxi);
        //     if(it>0)s.insert(it);
        // }
        // if(maxi<1)return 1;
        // //ans can lie only between 1 to n+1..n is the size of array(imp conclusion)
        // for(int i=1;i<=nums.size()+1;i++){
        //     if(s.find(i)==s.end())return i;
        // };
        // return maxi+1;

        //most efficient sol: try to place positive bits at the correct place.

        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i];
            while(x>=1&& x<=n&& nums[x-1]!=x&&x!=i+1){
                swap(nums[i],nums[x-1]);
                x=nums[i];
            }
        };
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1)return i+1;
        };
        return n+1;
    }
};