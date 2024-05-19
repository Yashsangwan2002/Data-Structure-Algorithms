class Solution {
public:
    unordered_map<char,int> m;
    bool check(string s){
        for(auto it:s){
            if(m.find(it)!=m.end())return false;
        };
        return true;
    };
    void fill(string s){
        for(auto it:s)m[it]++;
    }
    void remove(string s){
        for(auto it:s){
            m[it]--;
            if(m[it]==0)m.erase(it);
        }
    }
    int iterate(int ind,vector<string>& arr){
        if(ind==arr.size())return 0;
        int take=INT_MIN;
        if(check(arr[ind])){
            fill(arr[ind]);
            take=arr[ind].size()+iterate(ind+1,arr);
            remove(arr[ind]);
        };
        int notake=iterate(ind+1,arr);
        return max(take,notake);
    }
    int maxLength(vector<string>& arr) {
        return iterate(0,arr);
    }
};