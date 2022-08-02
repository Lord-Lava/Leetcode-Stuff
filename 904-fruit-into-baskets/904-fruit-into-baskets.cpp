class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i =0,j =0,n = fruits.size();
        int ans = 0;
        map<int,int>mp;
        int count = 0;
        while(j<n){
            mp[fruits[j]]++;
            if(mp[fruits[j]] == 1) {
                count++;
            }
            if(count<2) {
                ans = max(ans,j-i+1);
                j++;
            }
            else if(count == 2) {
                ans = max(ans,j-i+1);
                j++;
            } else if(count>2) {
                while(count>2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]] == 0) {
                        count--;
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};