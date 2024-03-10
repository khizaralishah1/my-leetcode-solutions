class Solution {
public:

    void prints(vector<vector<int>>& matrix, int n) {
        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < n; ++j )
                cout << matrix[i][j] << ' ';
            cout << endl;
        }
    }

    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> matrix(n);
        vector<int> a(n);
        for ( int j = 0; j < n; ++j )
            a[j] = 0;
        for ( int i = 0; i < n; ++i ) {
            matrix[i] = a;
        }

        int i, j, p, k = 0, value = 1;
        int end = n * n;
     
        while ( value <= end ) {
            i = j = k;

            if ( n == 1 ) { matrix[i][j] = value; return matrix; }

            for ( p = 0; p < n - 1; ++p ) {
                matrix[i][j] = value;
                ++j;
                ++value;
            }
            for ( p = 0; p < n - 1; ++p ) {
                matrix[i][j] = value;
                ++i;
                ++value;
            }
            for ( p = 0; p < n - 1; ++p ) {
                matrix[i][j] = value;
                --j;
                ++value;
            }
            for ( p = 0; p < n - 1; ++p ) {
                matrix[i][j] = value;
                --i;
                ++value;
            }
            ++k;
            n -= 2;
            //prints(matrix, matrix.size());
            //cout << endl << " k = " << k << endl;;
        }

        return matrix;

    }

};