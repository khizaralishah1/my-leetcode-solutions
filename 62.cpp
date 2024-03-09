class Solution {
public:

    int uniquePath(int m, int n, int** dp ) {
        if ( dp[m][n] != -1 ) return dp[m][n];
        else if ( m < 0 || n < 0 ) return 0;

        if ( n - 1 >= 0 ) {
            dp[m][n-1] = uniquePath(m, n - 1, dp);
            dp[m][n] = dp[m][n-1];
        }
            
        if ( m - 1 >= 0 )
            dp[m-1][n] = uniquePath(m-1, n, dp);

        if ( n - 1 >= 0 && m - 1 >= 0 )
            dp[m][n] += dp[m-1][n];
        else if ( m - 1 >= 0 ) {
            dp[m][n] = dp[m-1][n];
        }

        return dp[m][n];
    }

    int uniquePaths(int m, int n) {

        int **dp = new int*[m];
        
        for(int i=0;i<m; ++i) {
            dp[i] = new int[n];
            for(int j=0; j<n; ++j) {
                dp[i][j] = -1;
            }
        }
        dp[0][0] = 1;

        return uniquePath(m-1, n-1, dp);
    }
};