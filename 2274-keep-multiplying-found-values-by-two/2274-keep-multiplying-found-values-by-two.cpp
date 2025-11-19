class Solution {
public:
    int BinarySearch(vector<int>& nums, int original){
        int n = nums.size();
        int low = 0; 
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==original){
                original = 2*original;
                return BinarySearch(nums,original);
            }
            else if(nums[mid]<original){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return original;
    }
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        return BinarySearch(nums,original);
    }
};