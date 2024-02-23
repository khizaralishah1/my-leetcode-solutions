class Solution {
public:

    int trapSum(int left, int right, vector<int>& height) {
        if (left == -1 || right == -1 || left == right) return 0;

        int sum = 0;
        int minHeight = height[left] < height[right] ? height[left] : height[right]; 

        for ( int i = left; i <= right; ++i ) {
            if ( minHeight - height[i] > 0 ) {
                sum += minHeight - height[i];
                height[i] = minHeight;
            }
        }

        return sum;
    }

    int findMax(int left, int right, vector<int>& height) {
        if (left < 0 || right < 0 || left > height.size() - 1 || right > height.size() - 1) return -1;
        int max = height[left];
        int idx = left;
        for(int i = left; i <= right; ++i) {
            if (height[i] > max) { max = height[i]; idx = i; }
        }
        return idx;
    }

    int findMaxR(int left, int right, vector<int>& height) {
        if (left < 0 || right < 0 || left > height.size() - 1 || right > height.size() - 1) return -1;
        int max = height[right];
        int idx = right;
        for(int i = right; i >= left; --i) {
            if (height[i] > max) { max = height[i]; idx = i; }
        }
        return idx;
    }

    int anotherSum(int left, int right, vector<int>& height, bool leftSide) {
        if ( left < 0 || left > height.size() - 1 || right < 0 || right > height.size() - 1 || left == right || right - left < 2) return 0;

        if ( leftSide ) { // right contains overall max
            int leftMax = findMax(left, right - 1, height);
            return trapSum(leftMax, right, height) + anotherSum(left, leftMax, height, 1);
        } 
        else { // left contains overall max
            int rightMax = findMaxR(left+1, right, height);
            return trapSum(left, rightMax, height) + anotherSum(rightMax, right, height, 0);
        }
    }

    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        int left = 0, right = height.size() - 1;
        int overallMax = findMax(left, right, height);
        return anotherSum(left, overallMax, height, 1) + anotherSum(overallMax, right, height, 0);
    }
};