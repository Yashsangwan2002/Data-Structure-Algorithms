class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>s;
        for(auto it:nums1)s[it]++;
        vector<int> ans;
        for(auto it:nums2)if(s.find(it)!=s.end()&&s[it]>0){ans.push_back(it);s[it]--;};
        return ans;
    }
};