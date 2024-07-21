class Solution {
public:
    int maxOperations(string s) {
        int ans=0;
        int prevOne=0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='1'){
                prevOne++;
                if(s[i+1]=='0')ans+=prevOne;
            };
        };
        return ans;
    }
};