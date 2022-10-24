class Solution {
    static bool comp(pair<int,int>& p1, pair<int,int>& p2) {
        return p1.first > p2.first;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto& it: nums) {
            mp[it]++;
        }
        vector<pair<int,int>>v;
        for(auto &it:mp) {
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end(), comp);
        vector<int>ans;
        for(int i =0;i<k;i++) {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};