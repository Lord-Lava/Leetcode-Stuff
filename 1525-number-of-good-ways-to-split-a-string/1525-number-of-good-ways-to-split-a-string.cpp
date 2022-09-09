class Solution {
public:
    int numSplits(string s) {
        map<char,int>mp;
        vector<int>v;
        vector<int>a;
        for(auto it:s) {
            mp[it]++;
            v.push_back(mp.size());
        }
        mp.clear();
        for(int i = (int)s.size()-1; i>=0;i--) {
            mp[s[i]]++;
            a.push_back(mp.size());
        }
        int ans = 0;
        reverse(a.begin(), a.end()); 
        for(auto it:v) cout<<it<<" ";cout<<endl;
        for(auto it:a) cout<<it<<" ";cout<<endl;
        for(int i =0;i<s.size()-1;i++) {
            if(a[i+1] == v[i]) ans++;
        }
        return ans;
    }
};