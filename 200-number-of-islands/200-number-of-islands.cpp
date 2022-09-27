class Solution {
    void bfs (vector<vector<char>>& grid, int i, int j, int n, int m) {
        grid[i][j] = '0';
        queue<pair<int, int>>q;
        q.push({i, j});
        
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                int newX = x + dx[k];
                int newY = y + dy[k];
                
                if (newX >= 0 and newY >= 0 and newX < n and newY < m and grid[newX][newY] == '1') {
                    grid[newX][newY] = '0';
                    q.push({newX, newY});
                }
            }
        }    
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j, n, m);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};