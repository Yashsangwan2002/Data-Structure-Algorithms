class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> m;
        for(auto it:s)m[it]++;
        string ans="";
        for(auto it:order){
            if(m.find(it)!=m.end()){
                for(int i=0;i<m[it];i++)ans+=it;
                m[it]=0;
            };
        };
        for(auto it:m){
            if(it.second!=0){
                for(int i=0;i<it.second;i++)ans+=it.first;
            };
        };
        return ans;
    }
};