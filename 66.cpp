class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int e = digits.size() - 1;

        while ( e >= 0 ) {

            if ( digits[e] < 9 ) { ++digits[e]; break; }
            digits[e] = 0;
            --e;
        }

        if ( e == - 1 ) { digits.insert( digits.begin(), 1); }

        return digits;
    }
};