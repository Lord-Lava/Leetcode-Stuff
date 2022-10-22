class Solution {
    void bfs(int src, vector<bool>&vis, vector<vector<int>>&isConnected) {
        queue<int>q;
        q.push(src);
        vis[src] = 1;
        int n = isConnected.size();
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int j =0;j<n;j++) {
                if(j!=node && isConnected[node][j] && !vis[j]) {
                    vis[j] = 1;
                    q.push(j);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans =0;
        int n = isConnected.size();
        vector<bool>vis(n,0);
        
        for(int i =0;i<n;i++) {
            if(!vis[i]) {
                bfs(i,vis,isConnected);
                ans++;
            }
        }
        
        return ans;
    }
};