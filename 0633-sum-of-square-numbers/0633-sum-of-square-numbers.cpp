class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i=0;i*i<=c;i++){
            double temp=double(sqrt(c-long(i*i)))-int(sqrt(c-long(i*i)));
            if(temp==0)return true;
        }
        return false;
    }
};