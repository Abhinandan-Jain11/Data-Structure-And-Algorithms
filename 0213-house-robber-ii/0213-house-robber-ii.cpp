class Solution {
public:
    int solveMem(int ind,vector<int> &dp,  vector<int> &arr){
        if(ind==0) return arr[0];
        if(ind<0) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int pick = arr[ind] + solveMem(ind-2,dp,arr);
        int notPick = solveMem(ind-1,dp,arr);
        dp[ind] = max(pick,notPick);

        return dp[ind];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        vector<int> temp1,temp2;
        for(int i=0; i<n; i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(solveMem(n-2,dp1,temp1),solveMem(n-2,dp2,temp2));
    }
};