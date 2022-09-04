class Solution {
    int dp[101];
    int rec(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = rec(n-1) + rec(n-2) + rec(n-3);
    }
public:
    int tribonacci(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(n);
    }
};