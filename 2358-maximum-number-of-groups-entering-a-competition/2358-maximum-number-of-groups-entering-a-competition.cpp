class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        
        //if(n<3)return 1;
        
        int sum = 0;
        int j =1;
        int ans = 0;
        while(sum<=n){
            sum+=j;
            j++;
            ans++;
        }     
        
        return ans-1;
    }
};