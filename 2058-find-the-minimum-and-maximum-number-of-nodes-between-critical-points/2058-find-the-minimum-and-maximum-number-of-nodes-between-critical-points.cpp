/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int temp=head->val;
        head=head->next;
        vector<int>pos(2,0);
        vector<int>ans(2,-1);
        ans[0]=INT_MAX;
        int dis=1;
        while(head->next!=NULL){
            if((head->val>temp&&head->val>head->next->val)||(head->val<temp&&head->val<head->next->val)){
                if(pos[1]!=0)ans[0]=min(ans[0],dis-pos[1]);
                if(pos[0]!=0)ans[1]=max(ans[1],dis-pos[0]);
                if(pos[0]==0)pos[0]=dis;
                pos[1]=dis;
            };
            temp=head->val;
            head=head->next;
            dis++;
        };
        if(ans[0]==INT_MAX)return {-1,-1};
        return ans;
    };
};