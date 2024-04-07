class Solution {
public:
 bool checkValidString(string s) {
        stack<pair<char,int>> st, st1;

        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push({s[i],i});
            else if(s[i]=='*') st1.push({s[i],i});
            else if(s[i]==')') {
                if(!st.empty()) st.pop();
                else if(!st1.empty()) st1.pop();
                else return false;
            }
        }
        while(!st.empty() && !st1.empty()){
            if(st.top().second<st1.top().second){
                st.pop();
                st1.pop();
            }
            else return false;
        }
        if(st.empty()) return true;
        return false;
    }
};

