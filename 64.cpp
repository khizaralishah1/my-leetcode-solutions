class Solution {
public:

    bool** mygrid;
    int m, n;

    int pathsum(vector<vector<int>>& grid, int r, int c) {

        // for(int i=0;i<m;++i) {
        //     mygrid[i] = new bool[n];
        //     for(int j=0;j<n;++j) cout << mygrid[i][j] << " ";
        //     cout << endl;
        // }

        if ( r == 0 && c == 0 ) return grid[0][0];
        if (mygrid[r][c]) return grid[r][c];

        if ( r == 0 ) {
            grid[r][c] += pathsum(grid, r, c-1);
        } else if ( c == 0 ) {
            grid[r][c] += pathsum(grid, r-1, c);
        } else {
            grid[r][c] += min( pathsum(grid, r, c-1), pathsum(grid, r-1, c));
        }

        mygrid[r][c] = true;
        

        return grid[r][c];
    }

    int minPathSum(vector<vector<int>>& grid) { 
        m = grid.size();
        n = grid[0].size();

        if ( m == 1 ) {
            m = 0;
            for(int i=0; i<n; ++i) {
                m += grid[0][i];
            }
            return m;
        } else if ( n == 1 ) {
            n = 0;
            for(int i=0; i<m; ++i) {
                n += grid[i][0];
            }
            return n;
        }

        mygrid = new bool*[m];
        for(int i=0;i<m;++i) {
            mygrid[i] = new bool[n];
            for(int j=0;j<n;++j) mygrid[i][j] = false;
        }
        mygrid[0][0] = true;

        return pathsum(grid, m-1, n-1);
    }
};