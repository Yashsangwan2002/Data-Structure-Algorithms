class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>m;
        for(auto it:arr1)m[it]++;
        vector<int> ans;
        for(auto it:arr2){
            if(m.find(it)!=m.end()){
                for(int i=0;i<m[it];i++){
                    ans.push_back(it);
                };
                m.erase(it);
            };
        };
        for(auto it:m){
            for(int i=0;i<it.second;i++){
                ans.push_back(it.first);
            };
            m.erase(it.first);
        };
        return ans;
        
    }
};