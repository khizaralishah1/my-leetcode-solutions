class Solution {
public:

    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        int temp = -1;
        int k = n - 1;

        int a = 0;
        int b = (n-1) - k;
        int c = n - 1;

        while ( a < k ) {
            while ( b != k ) {
                temp = matrix[c][a];
                matrix[c][a] = matrix[k][c];
                matrix[k][c] = matrix[b][k];
                matrix[b][k] = matrix[a][b];
                matrix[a][b] = temp;
                ++b;
                --c;
            }
            ++a;
            --k;
            c = k;
            b = (n-1) - k;
        }
    }
};