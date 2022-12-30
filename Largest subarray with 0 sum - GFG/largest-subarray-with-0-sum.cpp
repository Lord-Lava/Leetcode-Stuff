//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        vector<int> pref(n,0);
        map<int,int>mp;
        pref[0] = A[0];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i-1] + A[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(pref[i] == 0) {
                ans = max(ans, i+1);
                continue;
            }
            if(mp.find(pref[i]) == mp.end()){
                mp[pref[i]] = i;
            }
            else {
                ans = max(ans, (i - mp[pref[i]]) );
            }
        }
        
        // for(int i =0;i<n;i++) {
        //     cout<<pref[i]<<" ";
        // }cout<<endl;
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends