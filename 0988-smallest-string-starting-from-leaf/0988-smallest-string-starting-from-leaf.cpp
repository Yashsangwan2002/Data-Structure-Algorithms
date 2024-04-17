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
    string smallest="|";
    void find(TreeNode* root,string path){
        if(root==NULL)return;
        path=char('a'+root->val)+path;
        if(root->left==NULL&&root->right==NULL)smallest=min(smallest,path);
        find(root->left,path);
        find(root->right,path);
    }
    string smallestFromLeaf(TreeNode* root) {
        find(root,"");
        return smallest;
    }
};