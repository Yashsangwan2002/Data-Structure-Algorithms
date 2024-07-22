class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,vector<string>>m;
        for(int i=0;i<names.size();i++){
            m[heights[i]].push_back(names[i]);
        };
        vector<string> ans;
        for(auto it:m){
            for(int i=0;i<it.second.size();i++){
                ans.push_back(it.second[i]);
            };
        };
        reverse(ans.begin(),ans.end());
        return ans;
    }
};