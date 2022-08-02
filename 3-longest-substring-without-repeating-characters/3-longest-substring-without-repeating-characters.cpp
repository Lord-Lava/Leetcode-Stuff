class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i =0,j=0,n=s.size();
        map<char,int>mp;
        int ans =0;
        while(j<n){
            mp[s[j]]++;
            if(mp[s[j]] == 1) {
                ans = max(ans,j-i+1);
                j++;
            } else if(mp[s[j]] > 1) {
                while(mp[s[j]] > 1){
                    mp[s[i]]--;
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};