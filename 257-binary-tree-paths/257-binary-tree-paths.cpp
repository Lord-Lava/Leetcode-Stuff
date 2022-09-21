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
    void rec(TreeNode* root,vector<int> &s,vector<vector<int>>&v) {
        if(root->left == NULL && root->right == NULL) {
            s.push_back(root->val);
            v.push_back(s);
            return;
        }
        s.push_back(root->val);
        if(root->left!=NULL) {
            rec(root->left, s, v);
            s.pop_back();
        }
        if(root->right!=NULL) {
            rec(root->right, s, v);
            s.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> v;
        vector<string>ans;
        vector<int>s;
        rec(root,s,v);
        for(auto it: v) {
            int m = it.size();
            string temp;
            for(int j = 0;j<m-1;j++) {
                temp+=to_string(it[j]) + "->";
            }
            temp+=to_string(it[m-1]);
            ans.push_back(temp);
        }
        return ans;
    }
};