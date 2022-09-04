class Solution {
    int dp[101];
    int rec(int n) {
        if(n==0 || n==1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = rec(n-1) + rec(n-2);
    }
public:
    int fib(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(n);
    }
};