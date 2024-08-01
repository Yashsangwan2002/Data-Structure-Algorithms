/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* curr =head;
        map<Node*,Node*> m;
        while(curr!=NULL){
            m[curr]=new Node(curr->val);
            curr=curr->next;
        };
        curr=head;
        while(curr!=NULL){
            m[curr]->next=m[curr->next];
            m[curr]->random=m[curr->random];
            curr=curr->next;
        };
        return m[head];
    }
};