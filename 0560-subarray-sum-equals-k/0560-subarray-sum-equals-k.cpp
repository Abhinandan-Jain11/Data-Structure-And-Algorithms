class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int n = nums.size();
      int cnt = 0;
      int prefSum = 0;
      unordered_map<long long int,int> mpp;
      mpp[0] = 1;
      for(int i=0; i<n; i++){
        prefSum += nums[i];
        int remove = prefSum-k;
        if(mpp.find(remove) != mpp.end()){
            cnt += mpp[remove];
        }
        mpp[prefSum]++;
      }
      return cnt;  
    }
};