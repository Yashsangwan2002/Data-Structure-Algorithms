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
    queue<ListNode*> q;
    int size=0;
    void fill(ListNode* root){
        if(root==NULL)return;
        fill(root->next);
        size++;
        q.push(root);
        return;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return NULL;
        fill(head);
        for(int i=0;i<k%size;i++){
            auto it=q.front();
            q.pop();
            if(!q.empty())it->next=q.back();
            q.push(it);
            q.front()->next=NULL;
        };
        return q.back();
    }
};