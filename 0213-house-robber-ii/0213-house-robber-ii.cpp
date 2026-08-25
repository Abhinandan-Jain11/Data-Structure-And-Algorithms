class Solution {
public:
    int spaceOpt(int n,vector<int> &arr){
        int prev2 = 0;
        int prev1 = arr[0];
        for(int i=1; i<n; i++){
            int pick = arr[i] + prev2;
            int notPick = prev1;
            int curr = max(pick,notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
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
        return max(spaceOpt(n-1,temp1),spaceOpt(n-1,temp2));
    }
};