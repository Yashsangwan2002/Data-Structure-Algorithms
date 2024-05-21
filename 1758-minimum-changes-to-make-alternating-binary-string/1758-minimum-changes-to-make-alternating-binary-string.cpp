class Solution {
public:
    int minOperations(string s) {
        int zero=0;
        int one=0;
        bool prev1=false;
        bool prev2=true;
        for(int i=0;i<s.length();i++){
            if(i==0){
                if(s[i]=='1')zero++;
                else one++;
            }
            else if(s[i]=='1'){
                if(prev1){
                    zero++;
                    prev1=false;
                }else prev1=true;
                if(prev2){
                    one++;
                    prev2=false;
                }else prev2=true;
            }else{
                if(!prev1){
                    zero++;
                    prev1=true;
                }else prev1=false;
                if(!prev2){
                    one++;
                    prev2=true;
                }else prev2=false;
            };
        };
        return min(one,zero);
    }
};