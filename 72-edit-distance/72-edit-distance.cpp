class Solution {
    int dp[501][501];
    int fun(string word1,string word2,int i,int j) {
        if(i==word1.length() and j==word2.length()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==word1.length()){
            return word2.length()-j;
        }
        if(j==word2.length()){
            return word1.length()-i;
        }
        int ans;
        if(word1[i]==word2[j]) ans = fun(word1,word2,i+1,j+1);
        else ans = min({1 + fun(word1,word2,i,j+1),1 + fun(word1,word2,i+1,j),1 + fun(word1,word2,i+1,j+1)});
        return dp[i][j] = ans;
    }
public:
    int minDistance(string word1, string word2) {
        if (word1 == "") return word2.size();
        if (word2 == "") return word1.size();
        memset(dp,-1,sizeof(dp));
        return fun(word1, word2, 0, 0);      
    }
};