class Solution {
    int dp[128][20001];
    int countVowelPermutationUtil(int n, char c) {
        if (n == 0) {
            return 1;
        }
        int ans = 0;
        if ( dp[c][n-1] != -1 ) {
            return dp[c][n-1];
        }
        if (c == 'a') {
            ans+= countVowelPermutationUtil(n-1, 'e')% (1000000007);
        } else if (c == 'e') {
            ans= (ans%(1000000007) + countVowelPermutationUtil(n-1, 'a')% (1000000007)) % (1000000007);
            ans= (ans%(1000000007) + countVowelPermutationUtil(n-1, 'i')% (1000000007)) % (1000000007);
        }else if (c == 'i') {
            ans= (ans%(1000000007) + countVowelPermutationUtil(n-1, 'a')% (1000000007)) % (1000000007);
            ans= (ans%(1000000007) + countVowelPermutationUtil(n-1, 'e')% (1000000007)) % (1000000007);
            ans= (ans%(1000000007) + countVowelPermutationUtil(n-1, 'o')% (1000000007)) % (1000000007);
            ans= (ans%(1000000007) + countVowelPermutationUtil(n-1, 'u')% (1000000007)) % (1000000007);
        }else if (c == 'o') {
            ans= (ans%(1000000007) + countVowelPermutationUtil(n-1, 'i')% (1000000007)) % (1000000007);
            ans= (ans%(1000000007) + countVowelPermutationUtil(n-1, 'u')% (1000000007)) % (1000000007);
        }else{
            ans= (ans%(1000000007) + countVowelPermutationUtil(n-1, 'a')% (1000000007)) % (1000000007);
        }
        return dp[c][n-1] = ans % (1000000007);
    }
public:
    int countVowelPermutation(int n) {
        int ans = 0;
        n--;
        memset(dp,-1,sizeof(dp));
        ans = (ans%(1000000007) + countVowelPermutationUtil(n,'a')%(1000000007)) % (1000000007);
        memset(dp,-1,sizeof(dp));
        ans = (ans%(1000000007) + countVowelPermutationUtil(n,'e')%(1000000007)) % (1000000007);
        memset(dp,-1,sizeof(dp));
        ans = (ans%(1000000007) + countVowelPermutationUtil(n,'i')%(1000000007)) % (1000000007);
        memset(dp,-1,sizeof(dp));
        ans = (ans%(1000000007) + countVowelPermutationUtil(n,'o')%(1000000007)) % (1000000007);
        memset(dp,-1,sizeof(dp));
        ans = (ans%(1000000007) + countVowelPermutationUtil(n,'u')%(1000000007)) % (1000000007);
        return ans % (1000000007);
    }
};