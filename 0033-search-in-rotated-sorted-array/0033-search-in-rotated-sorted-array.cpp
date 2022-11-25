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
    
    int binarySearch(vector<int>&nums, int lo, int hi, int target) {
        while(lo<=hi) {
            int mid = lo+(hi-lo)/2;
            if(nums[mid]<target) lo = mid+1;
            else if(nums[mid]>target) hi = mid-1;
            else return mid;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        int N = nums.size();
        int ans = binarySearch(nums,0,pivot,target) == -1 ? binarySearch(nums,(pivot+1)%N, N-1, target) : binarySearch(nums,0,pivot,target);
        return ans;
    }
};