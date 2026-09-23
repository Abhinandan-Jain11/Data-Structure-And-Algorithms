class Solution {
public:
    bool spaceOpt(vector<int>& arr, int sum){
        int n = arr.size();
        vector<int> prev(sum+1,0);
        vector<int> temp(sum+1,0);
        prev[0] = temp[0] = 1;
        
        if (arr[0] <= sum) {
            prev[arr[0]] = 1;
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<=sum; j++){
                int notPick = prev[j];
                int pick = 0;
                if(j>=arr[i]){
                    pick = prev[j-arr[i]];
                }
                temp[j] = pick | notPick;
            }
            prev = temp;
        }
        return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for(int i=0; i<nums.size(); i++){
            s += nums[i];
        }
        if(s%2 != 0) return false;
        int sum = s/2;
        return spaceOpt(nums,sum);
    }
};