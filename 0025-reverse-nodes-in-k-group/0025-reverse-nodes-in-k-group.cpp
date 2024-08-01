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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;
        int s=0;
        ListNode* curr=head;
        while(curr!=NULL){
            s++;
            curr=curr->next;
        };

        if(s<k)return head;
        int position=0;
        curr=head;
        ListNode* prev=NULL;
        while(position<k){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            position++;
        }
        if(curr!=NULL){
            ListNode* recursionhead=reverseKGroup(curr,k);
            head->next=recursionhead;
        }
        return prev;
    };
};