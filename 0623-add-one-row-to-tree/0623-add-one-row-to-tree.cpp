/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void create(TreeNode* root,int depth,int val,int curr){
        if(curr==depth)return;
        if(root==NULL)return;
        if(curr==depth-1&&root!=NULL){
            TreeNode* temp =new TreeNode(val);
            temp->left=root->left;
            root->left=temp;
            TreeNode* temp2 =new TreeNode(val);
            temp2->right=root->right;
            root->right=temp2;
            return;
        };
        curr++;
        if(curr<depth)create(root->left,depth,val,curr);
        if(curr<depth)create(root->right,depth,val,curr);
        return;

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* temp=new TreeNode(val);
            temp->left=root;
            return temp;
        };
        create(root,depth,val,1);
        return root;
    }
};