class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp='a';
        int f=0;
        int l=s.size()-1;
        while(f<l){
            temp=s[f];
            s[f]=s[l];
            s[l]=temp;
            f++;
            l--;
        };
    }
};