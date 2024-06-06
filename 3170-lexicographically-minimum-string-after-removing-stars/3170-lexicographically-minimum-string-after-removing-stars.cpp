class Solution {
public:
    string clearStars(string s) {
        map<char,stack<int>> m;
        for(int i=0;i<s.length();i++){
            if(s[i]!='*')m[s[i]].push(i);
            if(s[i]=='*'){
                auto ind=m[m.begin()->first].top();
                m[m.begin()->first].pop();
                if(m[m.begin()->first].empty())m.erase(m.begin()->first);
                s[ind]='*';
            };
        };
        string ans="";
        for(auto it:s){
            if(it!='*')ans+=it;
        }
        return ans;
    }
};