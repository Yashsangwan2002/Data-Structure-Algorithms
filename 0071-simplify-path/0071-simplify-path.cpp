class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp="";
        for(int i=0;i<=path.length();i++){
            if(path[i]=='/'||i==path.size()){
                if(temp==".."){
                    if(!st.empty())st.pop();
                    temp="";
                    continue;
                }else if(temp!="."&&temp!=""){
                    st.push('/'+temp);
                    temp="";
                    continue;
                }else if(temp==".")temp="";
            }else{
                temp+=path[i];
            };
        };
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans==""?"/":ans;
    };
};
