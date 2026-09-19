class Solution {
private:
    void dfs(int row, int col, int color, int prevColor, vector<vector<int>> &image){
        int n = image.size();
        int m = image[0].size();
        image[row][col] = color;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int i=0; i<4; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == prevColor){
                dfs(nrow,ncol,color,prevColor,image);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prevColor = image[sr][sc];
        if(prevColor == color) return image;
        dfs(sr,sc,color,prevColor,image);
        return image;
    }
};