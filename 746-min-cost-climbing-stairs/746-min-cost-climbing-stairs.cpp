class Solution {
    int dp[1001];
    int rec(int index,vector<int>&cost) {
        if(index >= cost.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int ans = INT_MAX;
        for(int step = 1;step<=2;step++) {
            int cst = cost[index] + rec(index+step, cost);
            ans = min(cst,ans);
        }
        return dp[index] = ans;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return min(rec(0,cost), rec(1,cost));
    }
};