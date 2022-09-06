class Solution {
    int dp[102];
    int n;
    int rec(int level, int n, vector<int>&nums) {
        // cout<<level<<" "<<n<<endl;
        
        //base case
        if(level >= n) return 0;
        //cache check
        if(dp[level] != -1) return dp[level];
        //compute / choice
        int ans = 0;
        //option 1: loot
        ans = max(ans,nums[level] + rec((level+2), n, nums));
        cout<<ans<<endl;
        //option 2: not loot
        ans = max(ans,rec((level+1), n, nums));
        // cout<<ans<<endl;
        
        //save and return
        return dp[level] = ans;
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        memset(dp,-1,sizeof(dp));
        int ans1 = rec(0,(int)nums.size()-1,nums);
        // cout<<ans1<<endl;
        memset(dp,-1,sizeof(dp));
        int ans2 = rec(1,nums.size(),nums);
        return max(ans1,ans2);
    }
};