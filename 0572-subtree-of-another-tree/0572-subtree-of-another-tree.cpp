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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL) return (p==q);
        return p->val == q->val && isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return root == subRoot;
        if(subRoot == NULL) return true;
        if (isSameTree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};