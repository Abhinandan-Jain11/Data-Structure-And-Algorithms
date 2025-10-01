class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = 0;
        while(numBottles >=1){
            empty = empty + numBottles;
            numBottles = empty/numExchange;
            ans += numBottles;
            empty = empty%numExchange;
        }
        return ans;
    }
};