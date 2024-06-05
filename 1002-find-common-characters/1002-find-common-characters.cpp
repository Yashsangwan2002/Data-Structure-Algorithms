class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char,int> m;
        for(auto it:words[0])m[it]++;
        for(int i=1;i<words.size();i++){
            unordered_map<char,int>m2;
            for(auto it:words[i]){
                if(m.find(it)!=m.end()&&m2[it]<m[it])m2[it]++;
            };
            m=m2;
        };
        vector<string> ans;
        for(auto it:m){
            for(int i=0;i<it.second;i++){
                ans.push_back(string(1, it.first));
            }
        }
        return ans;
    }
};