class Solution {
public:
    string minWindow(string s, string t) {
        int i =0, j=0, n=s.size(), start = 0, end =0, mini = INT_MAX;
        if(s.size() < t.size()) return "";
        map<char,int>mp;
        for(auto it:t)mp[it]++;
        int count = mp.size();
        while(j<n){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0)count--;
            }
            if(count == 0) {
                while(count == 0) {
                    if(mp.find(s[i]) != mp.end()) {
                        if(mp[s[i]] < 0){
                            mp[s[i]]++;
                            if(mp[s[i]] == 1){
                                count++;
                            }
                        } else {
                            if(j-i+1 < mini) {
                                mini = j-i+1;
                                start = i;
                                end = j;
                            }
                            break;
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        if(mini == INT_MAX)return "";

        return s.substr(start,end-start+1);
    }
};