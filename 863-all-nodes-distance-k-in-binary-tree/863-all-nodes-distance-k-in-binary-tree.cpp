/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void fun(map<TreeNode*, vector<TreeNode*>>&adj, TreeNode* root) {
        if(root == NULL) {
            return;
        }
        if(root->left!=NULL) {
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
        }
        if(root->right!=NULL) {
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
        }
        fun(adj ,root->left);
        fun(adj ,root->right);
    }
    
    void bfsDist(TreeNode* src, map<TreeNode*, vector<TreeNode*>>&adj, vector<int>& dist)     {
        queue<TreeNode*>q;
        q.push(src);
        dist[src->val] = 0;
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            vector<TreeNode*>v = adj[node];
            for(auto it: adj[node]) {
                if(dist[node->val] + 1 < dist[it->val]) {
                    dist[it->val] = dist[node->val] + 1;
                    q.push(it);
                }
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, vector<TreeNode*>>adj;
        fun(adj, root);
        // for(auto i:adj) {
        //     cout<<i.first->val<<" ";
        //     for(auto it:i.second) {
        //         cout<<it->val<<" ";
        //     } cout<<endl;
        // }
        if (adj.size() == 0) return {};
        TreeNode* src = target;
        int n = adj.size();
        vector<int>dist(n, INT_MAX);
        bfsDist(src, adj, dist);
        // for(auto it: dist){
        //     cout<<it<<" ";
        // }cout<<endl;
        vector<int>ans;
        for(int i =0;i<dist.size(); i++) {
            if(dist[i] == k){
                ans.push_back(i);
            }
        }
        return ans;
    }
};