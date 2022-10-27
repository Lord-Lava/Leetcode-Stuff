class Solution {
    int dp[101][101];
    int uniquePathsUtil(int m, int n) {
        //pruning
        if(m<0 || n<0) return 0;
        //base case
        if(m == 0 && n == 0) return 1;
        //cache check
        if(dp[m][n] != -1) return dp[m][n];
        //compute
        int ans = 0;
        ans+=uniquePathsUtil(m-1,n) + uniquePathsUtil(m,n-1);
        //save and return
        return dp[m][n] = ans;
    }
public:
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return uniquePathsUtil(m-1,n-1);
    }
};