class Solution {
    int dp[102][101];
    const int OFFSET = 2;
    int rec(int level, int lastLooted, vector<int>&nums) {
        //base case
        if(level >= nums.size()) return 0;
        //cache check
        if(dp[level][lastLooted+OFFSET] != -1) return dp[level][lastLooted+OFFSET];
        //compute / choice
        int ans = 0;
        //option 1: loot
        if(lastLooted!=level-1)
            ans = max(ans,nums[level] + rec(level+1, level, nums));
        //option 2: not loot
            ans = max(ans,rec(level+1, lastLooted, nums));
        //save and return 
        return dp[level][lastLooted+OFFSET] = ans;
    }
public:
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return rec(0,-2,nums);
    }
};