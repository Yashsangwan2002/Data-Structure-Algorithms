class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101,0);
        int maxi=INT_MIN;
        for(auto it:nums){
            freq[it]++;
            maxi=max(maxi,freq[it]);
        };
        int ans=0;
        for(auto it:freq){
            if(it==maxi)ans+=it;
        };
        return ans;
    }
};