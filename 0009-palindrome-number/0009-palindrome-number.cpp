class Solution {
public:
    bool isPalindrome(int x) {
        long long int rev = 0;
        int n = x;
        while(x>0){
            int d = x%10;
            rev = (long long)rev*10 + d;
            x=x/10;
        }
        if (rev == n) return true;
        return false;
    }
};