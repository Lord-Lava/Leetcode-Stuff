class Solution {
    int dp[102];
    int rec(int level, vector<int>&nums) {
        //base case
        if(level >= nums.size()) return 0;
        //cache check
        if(dp[level] != -1) return dp[level];
        //compute / choice
        int ans = 0;
        //option 1: loot
        ans = max(ans,nums[level] + rec(level+2, nums));
        //option 2: not loot
        ans = max(ans,rec(level+1, nums));
        //save and return 
        return dp[level] = ans;
    }
public:
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return rec(0,nums);
    }
};