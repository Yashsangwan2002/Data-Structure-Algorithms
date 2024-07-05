class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj=nums[0];
        int freq=0;
        for(auto it:nums){
            if(maj==it)freq++;
            else freq--;
            if(freq==0){maj=it;freq=1;}
        };
        return maj;

    }
};