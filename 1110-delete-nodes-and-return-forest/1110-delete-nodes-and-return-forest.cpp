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
    vector<TreeNode*> ans;
    unordered_map<int, int> m;

    TreeNode* iterate(TreeNode* root) {
        if (root == NULL) return NULL;

        root->left = iterate(root->left);
        root->right = iterate(root->right);

        if (m.find(root->val) != m.end()) {
            if (root->left && m.find(root->left->val) == m.end()) ans.push_back(root->left);
            if (root->right && m.find(root->right->val) == m.end()) ans.push_back(root->right);
            delete root;
            return NULL;
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (auto it : to_delete) m[it]++;
        if (root && m.find(root->val) == m.end()) ans.push_back(root);
        iterate(root);
        return ans;
    }
};