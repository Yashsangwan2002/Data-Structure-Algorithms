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
    vector<int> v;
    void iterate(TreeNode* root){
        if(root==NULL)return;
        v.push_back(root->val);
        iterate(root->right);
        iterate(root->left);
    }
    TreeNode* create(int start,int end){
        int ind=(start+end)/2;
        TreeNode* temp=new TreeNode(v[ind]);
        if(ind<end)temp->right=create(ind+1,end);
        if(ind>start)temp->left=create(start,ind-1);
        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) {
        iterate(root);
        sort(v.begin(),v.end());
        return create(0,v.size()-1);

    }
};