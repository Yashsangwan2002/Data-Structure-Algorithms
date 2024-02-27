class Solution {
public:
int fac(int n) {
        return n > 1 ? n * fac(n-1) : 1;
    }
   int countNumbersWithUniqueDigits(int n) {
        return n > 0 ? 9 * fac(9)/fac(10-n) 
                + countNumbersWithUniqueDigits(n-1) : 1;
    }
};