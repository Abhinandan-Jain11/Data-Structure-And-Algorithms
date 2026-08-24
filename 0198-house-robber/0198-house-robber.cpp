class Solution {
public:
    int spaceOpt(int n, vector<int> &nums){
        if(n == 0) return nums[0];
        if(n<0) return 0;

        int prev1 = nums[0];
        int prev2 = 0;

        for(int i=1; i<n; i++){
            int pick = nums[i];
            if(i>1) pick += prev2;
            int notPick = prev1;
            int curr = max(pick,notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return spaceOpt(n,nums);
    }
};