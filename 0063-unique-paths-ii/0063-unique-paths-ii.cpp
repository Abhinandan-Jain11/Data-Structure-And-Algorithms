class Solution {
public:
    int solveMem(int m, int n, vector<vector<int>> &obstacleGrid){

        vector<vector<int>> dp(m , vector<int>(n, -1));

        dp[0][0] = 1;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int up = 0;
                int left = 0;
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                if(i==0 && j==0){
                    continue;
                }else{
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                }
                dp[i][j] = up + left;
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return solveMem(m,n,obstacleGrid);
    }
};