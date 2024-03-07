class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (i < s.length() - 1 && s[i + 1] != ' ') {
                    reverse(temp.begin(), temp.end());
                    if (!ans.empty()) ans += " "; 
                    ans += temp;
                    temp = "";
                }
            } else {
                temp += s[i];
            }
        }
        if (!temp.empty()) {
            reverse(temp.begin(), temp.end());
            if (!ans.empty()) ans += " "; 
            ans += temp;
        }
        return ans;
    }
};
