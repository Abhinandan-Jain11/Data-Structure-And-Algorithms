class Solution {
public:
    long long findHrs(const vector<int> &piles, long long k){
        long long cnt = 0;
        for(long long pile : piles){
            cnt += (pile + k - 1) / k; 
        }
        return cnt;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());

        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(findHrs(piles, mid) <= h){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int)low; 
    }
};
