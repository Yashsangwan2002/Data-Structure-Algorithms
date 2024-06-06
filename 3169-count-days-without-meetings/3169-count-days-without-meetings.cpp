class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int ans=0;
        int prev=0;
        for(auto it:meetings){
            if(it[0]>prev)ans+=it[0]-prev-1;
            prev=max(prev,it[1]);
        };
        ans+=days-prev;
        return ans;
    }
};