class Solution {
public:
    int solveMem(int i, int j1, int j2, int n, int m, vector<vector<vector<int>>>&dp, vector<vector<int>> &grid){
        if(i>n-1 || j1<0 || j1>m-1 || j2<0 || j2>m-1) return -1e8;

        if(i == n-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi = -1e8;
        for(int dj1=-1; dj1<=1; dj1++){
            for(int dj2=-1; dj2<=1; dj2++){
                int cherries;

                if (j1 == j2){
                    cherries = grid[i][j1];
                }else{
                    cherries = grid[i][j1] + grid[i][j2];
                }    
                cherries += solveMem(i + 1,j1 + dj1,j2 + dj2,n, m, dp, grid);
                maxi = max(maxi, cherries);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m,-1)));
        return solveMem(0,0,m-1,n,m,dp,grid);
    }
};