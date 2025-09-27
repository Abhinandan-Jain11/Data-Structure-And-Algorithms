class Solution {
public:
    long long int findHrs(vector<int> &piles, int k){
        long long cnt = 0;
        for(int i=0; i<piles.size(); i++){
            cnt += ceil((double)piles[i]/(double)k);
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1; 
        int high = *max_element(piles.begin(), piles.end());
        int ans=INT_MAX;
        while(low<=high){
            int mid =(low+high)/2;
            long long int hrs = findHrs(piles,mid);
            if(hrs <= h){
                ans = min(ans,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};