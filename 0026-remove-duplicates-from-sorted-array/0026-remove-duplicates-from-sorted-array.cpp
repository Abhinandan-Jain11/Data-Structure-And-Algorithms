class Solution {
public:
    
    
    int removeDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int prev = INT_MIN;
        for(int i=0; i<n; i++){
            if(nums[i] != prev){
                ans.push_back(nums[i]);
                prev = nums[i];
            }
        }
        int k = ans.size();
        for(int i=0; i<k; i++){
            nums[i] = ans[i];
        }
        return k;
    }
};