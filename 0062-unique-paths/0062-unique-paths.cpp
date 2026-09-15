class Solution {
public:
    int solveMem(int r, int c, vector<vector<int>> & dp){

        if(r==0 && c==0) return 1;
        if(r<0 || c<0) return 0;

        if(dp[r][c] != -1) return dp[r][c];

        int up = solveMem(r-1,c,dp);
        int left = solveMem(r,c-1,dp);

        return dp[r][c] = up + left;
    }
    int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m , vector<int>(n, -1));
       return solveMem(m-1,n-1,dp);
    }
};