class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int curSum = 0;
        int n = prices.size();
        for(int i =1;i<n;i++) {
            curSum = max(0, curSum+=prices[i] - prices[i-1]);
            ans = max(ans, curSum);
        }
        return ans;
    }
};