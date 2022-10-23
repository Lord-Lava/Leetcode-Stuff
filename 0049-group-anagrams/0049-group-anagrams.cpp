class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<string,vector<string>>mp;
        for(int i=0;i<n;i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }
        vector<vector<string>>v;
        for(auto it:mp) {
            vector<string>temp;
            for(auto i: it.second) {
                temp.push_back(i);
            }
            v.push_back(temp);
        }
        return v;
    }
};