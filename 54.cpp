class Solution {
public:

    vector<int> result;


    void spiral(vector<vector<int>>& matrix, int i, int j) {
        int cols = matrix[0].size() - 2 * j; // 4 - 2 = 2
        int rows = matrix.size() - 2 * i;    // 3 - 2 = 1
        int istart = i; // 0
        int jstart = j; // 0

        if (cols == 1 && rows == 1) {
            result.push_back(matrix[i][j]);
            return;
        } else if (cols == 1) {
            for ( int k = 0; k < rows; ++k)
                result.push_back(matrix[i++][j]);
            return;
        } else if (rows == 1) {
            for ( int k = 0; k < cols; ++k)
                result.push_back(matrix[i][j++]);
            return;
        }

        for ( int k = 0; k < cols - 1;  ++k ) 
            result.push_back(matrix[i][j++]); // 2

        for ( int k = 0; k < rows - 1;  ++k ) 
            result.push_back(matrix[i++][j]); // 5 4

        for ( ; j > jstart;    --j ) 
            result.push_back(matrix[i][j]); // -1
        for ( ; i > istart;    --i ) 
            result.push_back(matrix[i][j]); // 0 8

    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i = 0, j = 0;
        int cols = matrix[0].size();
        int rows = matrix.size();

        if (cols == 1 && rows == 1) {
            result.push_back(matrix[i][j]);
        } else if (cols == 1) {
            for (int i = 0; i < rows; ++i)
                result.push_back(matrix[i][j]);
        } else if (rows == 1) {
            for (int j = 0; j < cols; ++j)
                result.push_back(matrix[i][j]);

        } else {
            while ( i < rows - 1 && j < cols - 1) {
                spiral(matrix, i, j);
                ++i;
                ++j;
            }
        }

        return result;
    }
};