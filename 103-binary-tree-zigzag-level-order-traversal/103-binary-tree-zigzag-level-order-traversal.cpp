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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        if(root == NULL) return {};
        q.push(root);
        vector<vector<int>>ans;
        bool flag = 0;
        while(!q.empty()) {
            int n = q.size();
            vector<int>v;
            for(int i =0;i<n;i++){   
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left!=NULL)
                q.push(node->left);
                if(node->right!=NULL)
                q.push(node->right);
            }
            if(flag) reverse(v.begin(), v.end());
            flag = !flag;
            ans.push_back(v);
        }
        return ans;
    }
};