class Solution {
public:
    int pivotIndex(vector<int>& nums) {
     int total=0;
     for(int i=0;i<nums.size();i++){
        total=total+nums[i];
     }if(0==(total-nums[0]))return 0;
     int sum=nums[0];
     for(int i=1;i<nums.size()-1;i++){
        int num=sum;
        sum=sum+nums[i];
        if(num==(total-sum))return i;
     } if(0==(total-nums[nums.size()-1]))return nums.size()-1;
     return -1;  
    }
};