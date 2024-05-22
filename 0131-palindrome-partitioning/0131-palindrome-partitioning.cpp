class Solution {
public:
    vector<vector<string>> ans;
    vector<string> v;
    bool check(string s){
        int f=0;
        int l=s.length()-1;
        while(f<l){
            if(s[f]!=s[l])return false;
            f++;l--;
        };
        return true;
    }
    void find(string s,int ind,int n){
        if(ind==n){
            ans.push_back(v);
        };
        string temp="";
        for(int i=ind;i<n;i++){
            temp+=s[i];
            if(check(temp)){
                v.push_back(temp);
                find(s,i+1,n);
                v.pop_back();
            };
        };
    };
    vector<vector<string>> partition(string s) {
        find(s,0,s.length());
        return ans;
    }
};