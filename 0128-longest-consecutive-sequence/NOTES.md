if(nums.size() == 0) return 0;
unordered_set<int>st(nums.begin(), nums.end());
int ans = 1;
for(int i =0;i<nums.size();i++) {
if(st.find(nums[i] - 1) == st.end()) {
int y = nums[i] + 1;
while(st.find(y) != st.end()) {
ans = max(ans, y-nums[i]+1);
y++;
}
}
}
return ans;