class Solution {
public:
    int spaceOpt(int n, vector<vector<int>> &triangle){

        vector<int> prev(n,0);
        vector<int> temp(n,0);

        for(int j=0; j<n; j++){
            prev[j] = triangle[n-1][j];
        }
        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                int down = triangle[i][j] + prev[j];
                int diagonal = triangle[i][j] + prev[j+1];

                temp[j] = min(down,diagonal);
            }
            prev = temp;
        }
        return prev[0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        return spaceOpt(n,triangle);
    }
};