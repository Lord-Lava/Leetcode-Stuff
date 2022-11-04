class Solution {
    char to_lower(char ch) {
        if(ch>='A' && ch<='Z') return ch+32;
        return ch;
    }
    bool isAlphaNumeric(char ch) {
        return (ch>='A' && ch<='Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
    }
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;
        while(i<=j) {
            if(!isAlphaNumeric(s[i])) {
                i++;
                continue;
            }
            if(!isAlphaNumeric(s[j])) {
                j--;
                continue;
            }
            if(to_lower(s[i]) != to_lower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};