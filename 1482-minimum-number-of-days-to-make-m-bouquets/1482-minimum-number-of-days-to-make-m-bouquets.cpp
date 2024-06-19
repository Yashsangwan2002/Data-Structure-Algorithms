class Solution {
public:
    int poss(vector<int>& bloomDay, int maxi, int k){
        int ans=0;int count=0;
        for(auto it:bloomDay){
            if(it<=maxi)count++;
            else{
                ans+=count/k;
                count=0;
            };
        }
        ans+=count/k;
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(long long)m*k)return -1;
        int maxi=INT_MIN;
        for(auto it:bloomDay)maxi=max(maxi,it);
        if(bloomDay.size()==(long long)m*k)return maxi;
        int left = 1;
        int right=maxi;
        int ans=0;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (poss(bloomDay, mid, k) >= m) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;

    }
};

