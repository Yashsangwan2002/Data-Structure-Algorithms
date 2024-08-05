class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>m;
        for(auto it:arr){
            m[it]++;
        };
        for(auto it:arr){
            if(m[it]==1){
                k--;
                if(k==0)return it;
            }
        }
        return  "";
    }
};