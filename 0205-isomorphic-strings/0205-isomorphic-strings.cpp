class Solution {
public:
  bool isIsomorphic(string s, string t) {
    vector<int> v1(200, 0); 
    vector<int> v2(200, 0); 
    if(s.length() != t.length()) {  
        return false;
    }
    for(int i = 0; i < s.length(); i++) { 
        if(v1[s[i]] != v2[t[i]]) { 
            return false; 
        }
        v1[s[i]] = i + 1; 
        v2[t[i]] = i + 1;
    }
    return true; 
}
};