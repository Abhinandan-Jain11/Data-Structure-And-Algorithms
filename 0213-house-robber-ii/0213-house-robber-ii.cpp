class Solution {
public:
    int solveTab(int n,vector<int> &arr){
        vector<int> dp(n,-1);

        dp[0] = arr[0];
        for(int i=1; i<n; i++){
            int pick = arr[i];
            if(i>1) pick += dp[i-2];
            int notPick = dp[i-1];
            dp[i] = max(pick,notPick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        
        vector<int> temp1,temp2;
        for(int i=0; i<n; i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(solveTab(n-1,temp1),solveTab(n-1,temp2));
    }
};