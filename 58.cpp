class Solution {
public:
    int lengthOfLastWord(string s) {

        int i = s.length() - 1;
        for ( ; i >= 0; --i )
            if ( s[i] != ' ' ) break;

        if ( i == 0 ) return 1;

        int j = i - 1;
        for ( ; j >= 0; --j )
            if ( s[j] == ' ' ) break;

        return i - j;
    }
};