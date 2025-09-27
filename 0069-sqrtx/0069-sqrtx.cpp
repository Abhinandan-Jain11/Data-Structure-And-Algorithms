class Solution {
public:
    int mySqrt(int n) {
        int sqr = INT_MIN;
        int low=1;
        int high = n/2;
        if(n==1){
            return 1;
        }
        if(n==0){
            return 0;
        }
        while(low<=high){
            int mid = (low+high)/2;
            if( (long long)mid*mid == n){
                sqr = mid;
                break;
            }
            else if((long long)mid*mid > n){
                high = mid-1;
            }
            else{
                sqr = max(sqr,mid);
                low = mid+1;
            }
            
            
        }
        return sqr;
    }
};