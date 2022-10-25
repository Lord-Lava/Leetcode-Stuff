class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int numXor = 0;
        int n = nums.size();
        for(int& num: nums) {
            numXor ^= num;
        }
        int totalXor = 0;
        for(int i = 0; i <= n; i++) {
            totalXor ^= i;
        }
        return numXor ^ totalXor;
    }
};