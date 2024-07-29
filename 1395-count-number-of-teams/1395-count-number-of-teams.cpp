class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans=0;
        for(int i=1;i<rating.size()-1;i++){
            int leftS=0;
            int leftG=0;
            int rightS=0;
            int rightG=0;
            for(int j=0;j<i;j++){
                if(rating[j]<rating[i])leftS++;
                if(rating[j]>rating[i])leftG++;
            };
            for(int j=i+1;j<rating.size();j++){
                if(rating[j]>rating[i])rightG++;
                if(rating[j]<rating[i])rightS++;
            };
            ans+=leftS*rightG;
            ans+=leftG*rightS;
        };
        return ans;
    }
};