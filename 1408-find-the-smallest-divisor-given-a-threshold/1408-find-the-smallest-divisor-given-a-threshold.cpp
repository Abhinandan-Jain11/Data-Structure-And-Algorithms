class Solution {
public:
    long long int divisionSum(vector<int> &nums, int d){
        long long int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            cnt += (nums[i]+d-1)/d;
        }
        return cnt;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high = *max_element(nums.begin(), nums.end());
        while(low<=high){
            int mid = (low+high)/2;
            long long int sum = divisionSum(nums,mid);
            if(sum<=threshold){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};