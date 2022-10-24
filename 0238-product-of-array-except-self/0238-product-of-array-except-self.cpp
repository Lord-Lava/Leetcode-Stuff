class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =  nums.size();
        int pref[n];
        pref[0] = nums[0];
        for(int i =1;i<n;i++) {
            pref[i] = pref[i-1] * nums[i];
        }
        int suff[n];
        suff[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--) {
            suff[i] = suff[i+1] * nums[i];
        }
        vector<int>ans(n);
        ans[0] = suff[1];
        ans[n-1] = pref[n-2]; 
        for(int i =1;i<n-1;i++) {
            ans[i] = pref[i-1]*suff[i+1];
        }
        return ans;
    }
};