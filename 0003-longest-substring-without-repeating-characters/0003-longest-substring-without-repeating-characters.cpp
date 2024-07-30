class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int last=0;int ans=INT_MIN;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
            while(m[s[i]]!=1){
                m[s[last]]--;
                last++;
            };
            ans=max(ans,i-last+1);
        };
        if(ans==INT_MIN)return 0;
        return ans;
    }
};