class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        for(int i=0;i<tickets.size();i++)q.push({tickets[i],i});
        int time=0;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            time++;
            temp.first--;
            if(temp.first==0){
                if(temp.second==k)return time;
                continue;
            };
            q.push(temp);
        };
        return -1;
    }
};