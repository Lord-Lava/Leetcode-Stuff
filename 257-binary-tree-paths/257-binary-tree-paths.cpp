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
    
    vector<vector<int>> ans;
    void rec(TreeNode* root, vector<int> temp){
        if(root->left == NULL and root->right==NULL){
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        if(root->left!=NULL){
            temp.push_back(root->val);
            rec(root->left,temp);
            temp.pop_back();
        }
        if(root->right!=NULL){
            temp.push_back(root->val);
            rec(root->right,temp);
        }
        
    }
    
    
    // void rec(TreeNode* root,string &s,vector<string>&v, int ctr) {
    //     if(root->left == NULL && root->right == NULL) {
    //         ctr++;
    //         s+=(root->val) + '0';
    //         v.push_back(s);
    //         s.clear();
    //         s+=ctr+'0';
    //         s+="->";
    //         return;
    //     }
    //     s+=(root->val) + '0';
    //     s+="->";
    //     if(root->left!=NULL)
    //     rec(root->left, s, v, 0);
    //     if(root->right!=NULL)
    //     rec(root->right, s, v, 0);
    // }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return {};
        // vector<string> v;
        rec(root,{});
        // string x;
        vector<string> a;
        for(int i=0;i<ans.size();i++){
            string x;
            for(int j=0;j<ans[i].size()-1;j++){
                x += to_string(ans[i][j]) + "->";
            }
            x += to_string(ans[i][ans[i].size()-1]);
            a.push_back(x);
            cout<<endl;
        }
        return a;
    }
};