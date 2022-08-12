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
    void rightView(TreeNode* root, vector<int>& ans, int level) {
        if(root == NULL) return;
        if(level >= ans.size()) ans.push_back(root->val);
        if(root->right!=NULL) rightView(root->right, ans, level + 1);
        if(root->left!=NULL) rightView(root->left, ans, level + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        rightView(root, ans, 0);
        return ans;
    }
};