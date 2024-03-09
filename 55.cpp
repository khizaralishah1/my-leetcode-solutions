class Solution {
public:

    int findMax(int i, vector<int>& nums) {

        if ( nums[i] + i >= nums.size() - 1 ) return nums.size() - 1;
        
        int start = i;
        int fixedIdx = i;
        int fixed = nums[i];

        for ( int k = 1; k <= fixed; ++k) {
            if ( fixedIdx + k > nums.size() - 1 ) return nums.size() - 1;
            else if ( nums[fixedIdx + k] + (fixedIdx + k) > nums[start] + start) {
                start = fixedIdx + k;
            }
        }
        return start;
    }

    bool canJump(vector<int>& nums) {

        if ( nums[0] >= nums.size() - 1) return true;
        
        int i = 0;

        while ( i != nums.size() - 1 ) {
            int input = i;
            i = findMax(input, nums);
            if ( i == nums.size() - 1 ) return true;
            else if (input == i) return false;
        }
        return true;
    }
};