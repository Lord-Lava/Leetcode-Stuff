class Solution {
    int dp[2501];
    int n;
    int rec(int level,vector<int>& nums) {
        //LIS [0...level]
        
        //pruning
        if(level<0) return 0;
        //base case
        
        //cache check
        if(dp[level]!=-1) return dp[level];
        //compute
        int ans = 1;
        for(int prev_taken = 0;prev_taken<level;prev_taken++) {
            if(nums[prev_taken] < nums[level])
                ans = max(ans,1+rec(prev_taken,nums));
        }
        //save and return
        return dp[level] = ans;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        int best = 0;
        for(int i =0;i<n;i++) {
            best = max(best, rec(i,nums));
        }
        return best;
    }
};