class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = -1;
        int l = 0;
        int n = nums.size();
        
        for(int i =0;i<n-1;i++){
            if(nums[i] < nums[i+1]){
                k = i;
            }    
        }
        
        if(k==-1){
            reverse(nums.begin(),nums.end());
            return;
        } 
        
        for(int i =0;i<n;i++){
            if(i>k && nums[i] > nums[k]){
                l = i;
            }
        }
        
        swap(nums[k],nums[l]);
        
        reverse(nums.begin()+k+1,nums.end());
    }
};