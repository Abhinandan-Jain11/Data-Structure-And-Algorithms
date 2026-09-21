class Solution {
public:
    int spaceOpt(vector<vector<int>> &matrix){
        int n = matrix.size();
        vector<int> prev(n,0);

        for(int j=0; j<n; j++){
            prev[j] = matrix[n-1][j];
        }
        int minSum = INT_MAX;
        for(int i=n-2; i>=0; i--){
            vector<int> temp(n,0);
            for(int j=0; j<n; j++){
                int down = prev[j];
                
                int downLeft = INT_MAX;
                if(j>0) downLeft = prev[j-1];

                int downRight = INT_MAX;
                if(j<n-1) downRight = prev[j+1];

                temp[j] = matrix[i][j] + min(down,min(downLeft,downRight));
            }
            prev = temp; 
        }
        int ans = INT_MAX;
        for(int j=0; j<n; j++){
            ans = min(ans, prev[j]);
        }
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        return spaceOpt(matrix);
    }
};