class Solution {
public:

    bool exists(vector<int>& inner, vector<vector<int>>& res) {

        for ( int p = 0; p < res.size(); ++p ) {
            if ( res[p].size() == inner.size() ) {
                int i;
                for ( i = 0; i < res[p].size(); ++i ) {
                    if (res[p][i] != inner[i])
                        break;
                }
                if ( i == inner.size() ) return true;
            }
        }
        
        return false;
    }

    void putter( int n, vector<vector<int>>& v ) {
        int size = v.size();
        int insize = v[0].size();
        vector<int> blueprint;
        vector<int> cur;

        for( int p = 0; p < size; ++p ) {
            blueprint = v[0];
            v.erase( v.begin() );

            for( int i = 0; i < insize + 1; ++i ) {
                cur = blueprint;
                while ( i < cur.size() && cur[i] == n ) ++i; 
                cur.insert(cur.begin() + i, n);
                if ( ! exists(cur, v) ) v.push_back(cur);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> temp;

        vector<int> t2;
        t2.push_back(nums[0]);
        temp.push_back(t2);

        for (int i = 1; i < nums.size(); ++i )
            putter(nums[i], temp);

        return temp;

    }
};