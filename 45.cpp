class Solution {
public:

    int findMax(int l, int r, vector<int>& nums) {
        int max = nums[l] + l;
        int idx = l;
        for ( int i = l + 1; i <= r; ++i ) {
            if ( nums[i] + i >= max ) {
                max = nums[i] + i;
                idx = i;
                //cout << " idd = " << idx << " max = " << nums[i] + i << endl;
            }
        }

        //cout << "out with idx " << idx << endl;
        return idx;
    }

    int jump(vector<int>& nums) {

        int size = nums.size() - 1;

        if( size == 0 ) return 0;

        int idx = 0, r = 0, j = 0, oldIdx = 0;
        
        while ( idx < size ) {
            r = (idx + nums[idx]) > size ? size : (idx + nums[idx]);
            if ( r == size ) return j + 1;

            oldIdx = idx;
            //cout << "entering with left and right " << idx << " " << r << endl;
            idx = findMax( idx, r, nums );
            //cout << " idx = " << idx << endl;

            if ( nums[oldIdx] + oldIdx > nums[idx] + idx) {
                if ( idx + nums[idx] == size )
                    return j + 2;
                else
                    idx = oldIdx + nums[oldIdx];
            }

            ++j;

            //cout << " j = " << j << endl;
        }

        return j;
    }
};