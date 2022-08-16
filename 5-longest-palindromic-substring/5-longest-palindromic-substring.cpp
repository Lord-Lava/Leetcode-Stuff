class Solution {
    int expandFromMiddle(string s, int left, int right) {
        while(left >=0 && right < s.size() && s[right] == s[left]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int end = 0;
        for(int i =0;i<n;i++) {
            int len1 = expandFromMiddle(s, i, i);
            int len2 = expandFromMiddle(s, i, i+1);
            int len = max(len1, len2);
            if(len > end - start + 1) {
                start = i - ((len-1) / 2);
                end = i + len/2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};