class Solution {
    int dp[102][102];
    int rec(int i, int j, vector<int>&cuts) {
        //min cost to cut between (arr[i]...arr[j])
        
        //pruning
        
        //base case
        if(i+1 == j) {
            return 0; //since no cuts can be made in between
        }
        //cache check
        if(dp[i][j] != -1) return dp[i][j];
        //compute
        int ans = 1e9;
        for(int p=i+1;p<=j-1;p++) {
            ans = min(ans, cuts[j]-cuts[i] + rec(i,p,cuts) + rec(p,j,cuts)); 
        }
        //save and return
        return dp[i][j] = ans;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,m-1,cuts);
    }
};