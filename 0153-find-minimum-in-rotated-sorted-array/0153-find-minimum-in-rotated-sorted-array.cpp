class Solution {
    int findPivot(vector<int>&nums) {
        int N = nums.size();
        int lo = 0;
        int hi = N-1;
        while(lo<=hi) {
            int mid = lo+(hi-lo)/2;
            if(nums[(mid-1+N)%N] < nums[mid] && nums[(mid+1)%N] < nums[mid]) {
                return mid;
            } else if(nums[mid] >= nums[lo]){
                lo = mid+1;
            } else if(nums[mid] <= nums[hi]) {
                hi = mid-1;
            } 
        }
        return -1;
    }
public:
    int findMin(vector<int>& nums) {
        int minIdx = (findPivot(nums) + 1)%nums.size();
        return nums[minIdx];
    }
};