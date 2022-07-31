class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
//         sort(grades.begin(), grades.end());
        
//         for(auto it:grades)cout<<it<<" ";cout<<endl;
        
        if(n<3)return 1;
        int sum = 0;
        int j =1;
        int ans = 0;
        while(sum<=n){
            sum+=j;
            j++;
            ans++;
        }
        // cout<<j<<" "<<sum<<endl;
        // j--;
        // int ans = j;
        // sum-=j;
        // int rem = n-sum;
        // int s = 0;
        // for(int i=0;i<rem;i++){
        //     s+=grades[n-i-1];
        // }
        // j--;
        // int s1=0;
        // for(int k = ;k<j;k--){
        //     s1+=grades[n-k-1];
        // }
        // if(s1>=s){
        //     ans--;
        // }
        
        return ans-1;
    }
};