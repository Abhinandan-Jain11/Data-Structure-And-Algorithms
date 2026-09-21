class Solution {
public:
    int solveTab(vector<vector<int>> &matrix){
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));

        for(int j=0; j<n; j++){
            dp[n-1][j] = matrix[n-1][j];
        }
        int minSum = INT_MAX;
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int down = dp[i+1][j];
                
                int downLeft = INT_MAX;
                if(j>0) downLeft = dp[i+1][j-1];

                int downRight = INT_MAX;
                if(j<n-1) downRight = dp[i+1][j+1];

                dp[i][j] = matrix[i][j] + min(down,min(downLeft,downRight));
            } 
        }
        int ans = INT_MAX;
        for(int j=0; j<n; j++){
            ans = min(ans, dp[0][j]);
        }
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        return solveTab(matrix);
    }
};