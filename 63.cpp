class Solution {
public:

    int **dp;

    int paths(vector<vector<int>>& obstacleGrid, int m, int n) {
        if ( obstacleGrid[m][n] == 1 ) { dp[m][n] = 0; }
        if ( dp[m][n] != -1 ) return dp[m][n];

        if ( m == 0 ) {
            dp[m][n-1] = paths(obstacleGrid, m, n - 1);
            return dp[m][n-1];
        } else if ( n == 0 ) {
            dp[m-1][n] = paths(obstacleGrid, m - 1, n);
            return dp[m-1][n];
        }
        
        dp[m][n-1] = paths(obstacleGrid, m, n - 1);
        dp[m-1][n] = paths(obstacleGrid, m - 1, n);

        return dp[m][n-1] + dp[m-1][n];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        dp = new int*[m];
        for(int i=0;i<m;++i) { dp[i] = new int[n]; for(int j=0;j<n;++j) dp[i][j] = -1; }
        dp[0][0] = 1;

        return paths(obstacleGrid, m - 1, n - 1); // 2 2
    }
};