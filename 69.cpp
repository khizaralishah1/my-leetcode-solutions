class Solution {
public:

    int mySqrt(int x) {

        if ( x <= 1 ) return x;
        
        long long int m; // 1 2 3 4 5 6 7 8 9 10
        //                  l r         x          

        int r = x;
        int l = 1;
        long long int square = 0;

        while ( 1 ) {

            m = r;
            m += l;
            m /= 2;
            
            square = m;
            square *= m;
            if ( square > 2147483647) { r = m; continue; }

            if ( square == x ) {
                return m;
            }
            else if ( square > x ) {
                r = m;
            } else {
                l = m;
            }

            if ( r - l == 1 ) return l;
        }

        return m;
    }
};