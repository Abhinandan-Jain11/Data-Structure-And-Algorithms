class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            int a = nums[i];
            int more = target-a;
            if(mpp.find(more)!=mpp.end()){
                int j = mpp[more];
                ans.push_back(j);
                ans.push_back(i);
                break;
            }
            mpp[a] = i;
        }
        return ans;
    }
};