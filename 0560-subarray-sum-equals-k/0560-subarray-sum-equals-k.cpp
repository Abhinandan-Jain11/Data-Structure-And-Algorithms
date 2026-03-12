class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mpp;
        mpp[0]=1;
        int prefS = 0;
        int count = 0;
        for(int i=0; i<n; i++){
            prefS += nums[i];
            int rem = prefS-k;
            count += mpp[rem];
            mpp[prefS]+=1;
        }
        return count;
    }
};