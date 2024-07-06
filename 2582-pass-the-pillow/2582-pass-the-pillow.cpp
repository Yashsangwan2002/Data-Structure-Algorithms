class Solution {
public:
    int passThePillow(int n, int time) {
        int cycle = 2*(n-1);
        int remTime = time % cycle; 
        if (remTime < n - 1) {
            return remTime + 1;
        } else {
            return n - (remTime - (n - 1));
        }
    }
};