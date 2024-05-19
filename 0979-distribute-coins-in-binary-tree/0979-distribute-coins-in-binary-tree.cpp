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
    int ans=0;
    int iterate(TreeNode* root){
        if(root==NULL)return 0;
        int state=0;
        int temp=0;
        state+=iterate(root->left);
        state+=iterate(root->right);
        if(state+root->val>1)temp= state+root->val-1;
        if(state+root->val<0)temp= state+root->val-1;
        if(state+root->val==0)temp= -1;
        ans+=abs(temp);
        return temp;
    }
    int distributeCoins(TreeNode* root) {
        iterate(root);
        return ans;
    };
};