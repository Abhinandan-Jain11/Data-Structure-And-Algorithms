class Solution {
private:
    void bfs(int row, int col, vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        grid[row][col] = '0';
        queue<pair<int,int>> q;
        q.push({row,col});

        // 4 directions: up, down, left, right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1'){
                    grid[nrow][ncol] = '0';
                    q.push({nrow,ncol});
                }
            }

        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    bfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};