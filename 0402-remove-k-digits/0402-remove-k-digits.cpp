class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        for(auto it:num){
             while (k > 0 && !ans.empty() && ans.back() > it) {
                ans.pop_back();
                k--;
            }
            if(ans==""&&it=='0')continue;
            ans.push_back(it);
        };
        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }
        return ans==""?"0":ans;
    }
};