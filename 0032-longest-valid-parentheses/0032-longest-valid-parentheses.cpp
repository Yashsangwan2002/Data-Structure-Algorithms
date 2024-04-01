class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);int ans=INT_MIN;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')st.push(i);
            else {
                st.pop(); 
                if(st.empty()){
                       st.push(i);
                }else{
                    ans=max(ans,i-st.top());
                }
            };
        };
        if(ans==INT_MIN)return 0;
        return ans;
    }
};