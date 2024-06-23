class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans=0;
        multiset<int> s;
        int prev=0;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
           while (*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[prev]));
                ++prev;
            }
            ans=max(ans,(i-prev+1));
        };
        return ans;
    }
};