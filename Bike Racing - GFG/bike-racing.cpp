// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isAlarmOn (long mid, long N, long M, long L, long H[], long A[]) {
        long sum = 0;
        for(long i =0;i<N;i++){
            if(H[i]+mid*A[i]>=L){
                sum+=H[i]+mid*A[i];
            }
        }
        if(sum>=M) return 1;
        return 0;
    }
    long buzzTime(long N, long M, long L, long H[], long A[])
    {
        long lo = 0;
        long hi = 1e9;
        long ans = 0;
        
        while(lo<=hi){
            long mid = lo+(hi-lo)/2;
            if(isAlarmOn(mid,N,M,L,H,A)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends