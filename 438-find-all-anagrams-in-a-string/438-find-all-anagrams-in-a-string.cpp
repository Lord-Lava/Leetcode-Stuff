class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i = 0;
        int j = 0;
        int n = s.size();
        map<char,int>mp;
        for(auto it:p) {
            mp[it]++;
        }
        
        vector<int>ans;
        int k = p.size();
        int ctr=mp.size();
        while(j<n){
            if(mp.find(s[j]) != mp.end()) {
              mp[s[j]]--;
                if(mp[s[j]]==0)
              ctr--;  
            } 
            
            if(j-i+1 == k) {
                if(ctr == 0) ans.push_back(i);
                if(mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if(mp[s[i]] == 1) {
                        ctr++;
                    }
                }
                i++;
                j++;
            } else {
                j++;
            }
        }
        return ans;
    }
};