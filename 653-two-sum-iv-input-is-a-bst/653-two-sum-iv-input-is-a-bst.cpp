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
    bool search(TreeNode* root,TreeNode* node , int target) {
        if(root == NULL) return false;
        if(root!=node && root->val == target) return true; 
        if(root->val < target) return search(root->right, node, target);
        return search(root->left, node, target);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            // cout<<" "<<k-node->val<<" "<<search(root,k-node->val)<<"\n";
            if(search(root,node ,k-node->val)) return true;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return false;
    }
};