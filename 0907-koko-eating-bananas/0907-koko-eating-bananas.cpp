class Solution {
public:
    long long findHrs(const vector<int> &piles, int k){
        long long cnt = 0;
        for(int i = 0; i < piles.size(); i++){
            cnt += (piles[i] + k - 1) / k;  
        }
        return cnt;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high){
            int mid = low + (high - low)/2;
            if(findHrs(piles, mid) <= h){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
