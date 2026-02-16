class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int f = 0;
        for(int i=0; i<n-1; i++){
            if(nums[i]>nums[i+1]){
                f++;
            }
        }
        if(nums[n-1]>nums[0]){
            f++;
        }
        if(f==0 || f==1){
            return true;
        }
        return false;
    }
};