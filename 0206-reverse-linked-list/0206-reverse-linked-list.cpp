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
    int flag=0;
    ListNode* ans=NULL;
    void rev(ListNode* root,ListNode* parent){
        if(root==NULL)return;
        rev(root->next,root);
        if(flag==0){
            ans=root;
            flag++;
        };
        root->next=parent;
        return;
    }
    ListNode* reverseList(ListNode* head) {
        rev(head,NULL);
        return ans;
    }
};