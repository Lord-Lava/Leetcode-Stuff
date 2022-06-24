// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    void bfs (vector<vector<char>>& grid, int i, int j, int n, int m) {
        grid[i][j] = '0';
        queue<pair<int, int>>q;
        q.push({i, j});
        
        int dy[] = {0, 0, -1, 1, -1, 1, -1 ,1};
        int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            grid[x][y] = '0';
            q.pop();
            
            for (int k = 0; k < 8; k++) {
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
    // Function to find the number of islands.
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

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends