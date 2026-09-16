class Solution {
public:
    int spaceOpt(int m, int n, vector<vector<int>> &grid){

        vector<int> prev(n,0);

        for(int i=0; i<m; i++){
            vector<int> temp(n,0);
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                    temp[0] = grid[0][0];
                    continue;
                }
                int up = 0;
                int left = 0;
                if(i>0) up = grid[i][j] + prev[j];
                else up = INT_MAX;
                if(j>0) left = grid[i][j] + temp[j-1];
                else left = INT_MAX;
                temp[j] = min(up,left);
            }
            prev = temp;
        }
        return prev[n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return spaceOpt(m,n,grid);
    }
};