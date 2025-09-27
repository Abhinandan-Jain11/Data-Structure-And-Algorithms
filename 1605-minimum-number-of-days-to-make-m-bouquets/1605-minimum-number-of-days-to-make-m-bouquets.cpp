class Solution {
public:
    long long int noOfBouquets(vector<int> &bloomDay, int k, int days){
        long long int cnt = 0;
        int m = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= days){
                cnt++;
            }
            else{
                m+=cnt/k;
                cnt = 0;
            }
        }
        m += cnt/k;
        return m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()){
            return -1;
        }
        int low=*min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low<=high){
            int mid=(low+high)/2;
            long long int bouquets =  noOfBouquets(bloomDay,k,mid);
            if(bouquets >= m){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};