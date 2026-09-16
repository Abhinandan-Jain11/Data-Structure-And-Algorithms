class Solution {
public:
    int solveMem(int r, int c, vector<vector<int>> &dp, vector<vector<int>> &grid){

        if(r==0 && c==0) return grid[0][0];
        if(r<0 || c<0) return INT_MAX;

        if(dp[r][c] != -1) return dp[r][c];

        int up = solveMem(r-1, c, dp, grid);
        int left = solveMem(r, c-1, dp, grid);

        if(up != INT_MAX) up += grid[r][c];

        if(left != INT_MAX) left += grid[r][c];

        return dp[r][c] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int> (n,-1));
        return solveMem(m-1,n-1,dp,grid);
    }
};