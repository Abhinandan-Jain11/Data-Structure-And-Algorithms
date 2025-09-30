class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        while(n>1){
            vector<int> newNums;
            for(int j=0; j<n-1; j++){
                newNums.push_back((nums[j] + nums[j+1])%10);
            }
            --n;
            nums = newNums;
        }
        return nums[0];
    }
};