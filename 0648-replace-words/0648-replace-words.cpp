class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,int> m;
        for(auto it:dictionary)m[it]++;
        string word="";
        string ans="";
        for(int i=0;i<sentence.length();i++){
            word+=sentence[i];
            if(sentence[i]==' '){ans+=word;word="";};
            if(m.find(word)!=m.end()){
                ans+=word;
                word="";
                while(i+1<sentence.length()&&sentence[i+1]!=' ')i++;
            }
        };
        if(word!="")ans+=word;
        return ans;
    }
};