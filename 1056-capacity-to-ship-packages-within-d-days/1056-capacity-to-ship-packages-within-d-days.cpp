class Solution {
public:
    int numberOfDays(vector<int> &weights, int capacity){
        int cnt=1;
        int load = 0;
        for(int i=0; i<weights.size(); i++){
            if(load + weights[i] > capacity){
                cnt++;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return cnt;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high=0;
        for(int i=0; i<weights.size(); i++){
            high += weights[i];
        }
        while(low<=high){
            int mid = (low+high)/2;
            int requiredDays = numberOfDays(weights,mid);
            if(requiredDays <= days){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};