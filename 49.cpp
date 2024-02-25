class Solution {
public:

    int arr[26];

    bool sums(string& a, string& b) {
        
        bool check = true;

        if ( a.length() == b.length() ) {
            int as = 0, bs = 0;
            for ( int i = 0; i < a.length(); ++i ) {
                arr[a[i] - 97] += 1;
                arr[b[i] - 97] -= 1;
                //sum method altern please do here
            }

            for(int i=0; i<26; ++i) {
                if (arr[i] != 0) {
                    arr[i] = 0;
                    check = false;
                }
            }
            
            return check;
        }

        return false;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> result;

        for(int i=0; i<26; ++i) arr[i] = 0;

        for( int i = 0; i < strs.size(); ++i ) {
            vector<string> cur;
            cur.push_back(strs[i]);
            for ( int k = i + 1; k < strs.size(); ++k ) {
                if ( sums(strs[i], strs[k]) ) {
                    cur.push_back(strs[k]);
                    strs.erase(strs.begin()+k);
                    --k;
                }
            }
            result.push_back(cur);
        }

        return result;
    }
};