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
    int maxPathUtil(TreeNode* root, int& ans) {
        if(root == NULL) return 0;
        int left = max(0,maxPathUtil(root->left, ans));
        int right = max(0,maxPathUtil(root->right, ans));
        int curMax = root->val+left+right;
        ans = max(ans, curMax);
        return root->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = -1e9;
        maxPathUtil(root, ans);
        return ans;
    }
};