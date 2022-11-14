class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int j = 0;
        map<int,int>mp;
        int ans = 0;
        for(int i =0;i<n;i++) {
            mp[s[i]]++;
            while((int)mp.size() < i-j+1) {
                mp[s[j]]--;
                if(mp[s[j]]==0) mp.erase(s[j]);
                j++;
            }
            if((int)mp.size() == i-j+1) {
                ans = max(ans,(int)mp.size());
            }
        }
        return ans;
    }
};