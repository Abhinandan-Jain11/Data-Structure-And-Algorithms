class Solution {
public:
    bool canWeSplit(vector<int> &nums,int mid, int k){
        int currentSum = 0;
        int cnt = 1;
        for(int i=0; i<nums.size(); i++){
            if(currentSum+nums[i]> mid){
                cnt++;
                currentSum = nums[i];
            }
            else{
                currentSum += nums[i];
            }
        }
        if(cnt<=k){
            return true;
        }
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high = 0;
        for(int i=0; i<n; i++){
            high += nums[i];
        }
        while(low<=high){
            int mid = (low+high)/2;
            if(canWeSplit(nums,mid,k) == true){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};