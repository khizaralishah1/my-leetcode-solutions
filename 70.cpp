class Solution {
public:

    int climbStairs(int n) {

        if ( n <= 3 ) return n;

        int a = 2;
        int b = 3;
        int c;
        n -= 3;
        while ( n != 0 ) {
            c = a + b;
            a = b;
            b = c;
            --n;
        }
        return c;
    }
};