//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    map<char,int>mp;
	    for(auto it: pat) mp[it]++;
	    int count = mp.size(), k = pat.size(), j=0, ans = 0;
	    int n = txt.size();
	    for(int i=0; i<n; i++) {
	        if(mp.find(txt[i]) != mp.end()) {
	            mp[txt[i]]--;
	            if(!mp[txt[i]]) count--;
	        }
	        while(j<n && i-j+1 > k) {
	            if(mp.find(txt[j]) != mp.end()) {
	                if(mp[txt[j]]==0) {
	                    count++;
	                }
	                mp[txt[j]]++;
	            }
	            j++;
	        }
	        
	        if(i-j+1 == k && count == 0) ans++;
	    }
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends