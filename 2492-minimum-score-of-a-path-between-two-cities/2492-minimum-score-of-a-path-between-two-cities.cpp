class Solution {
    int ans;
    void dfs(int src, vector<pair<int,int>>adj[], vector<int>&vis) {
        vis[src] = 1;
        for(auto it: adj[src]) {
            ans = min(ans, it.second);
            if(!vis[it.first]) {
                dfs(it.first, adj, vis);
            }
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        int m = roads.size();
        for(int i = 0;i<m;i++) {
            int u = roads[i][0]-1;
            int v = roads[i][1]-1;
            int w = roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<int>vis(n, 0);
        ans = INT_MAX;
        dfs(0, adj, vis);
        return ans;
    }
};