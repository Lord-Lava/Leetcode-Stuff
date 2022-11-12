class Solution {
    void solve(int level,vector<int>&temp ,vector<int>&candidates, int target, vector<vector<int>>& ans, int n) {
        //base case
        if(level == n) {
            if(target == 0) {
                ans.push_back(temp);
            }
            return;
        }
        //check/choice
        //pick:
        if(candidates[level] <= target) {
            temp.push_back(candidates[level]);
            solve(level, temp, candidates, target-candidates[level], ans, n);
            temp.pop_back();
        } 
        //not pick:
        solve(level+1, temp, candidates, target, ans, n);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0, temp, candidates, target, ans, candidates.size());
        return ans;
    }
};