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
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    
    void fun(TreeNode* root, int& diameter) {
        if(root == NULL) return;
        int leftH = height(root->left);
        int rightH = height(root->right);
        diameter = max(diameter, leftH + rightH);
        fun(root->left, diameter);
        fun(root->right, diameter);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        fun(root, diameter);
        return diameter;
    }
};