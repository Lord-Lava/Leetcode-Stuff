class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =  nums.size();
        vector<int>ans(n,1);
        for(int i =0, pre = 1, suff =1;i<n;i++) {
            ans[i]*=pre;
            pre*=nums[i];
            ans[n-i-1]*=suff;
            suff*=nums[n-i-1];
        }
        return ans;
    }
};