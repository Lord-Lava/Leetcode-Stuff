class Solution {
public:
    int tribonacci(int n) {
        int a = 0, b = 1, c = 1;
        
        if ( n == 0) {
            return a;
        } else if (n <= 2) return c;
        // 0 1 1 2 4 7 13 24 ...
        
        for (int i = 3; i <= n; i++) {
            int d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        
        
        return c;
    }
};