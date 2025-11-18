class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int index = -1;
        for(int i=0; i<n; i++){
            if(bits[i]==1){
                i++;
            }else if(bits[i]==0){
                index = i;
            }
        }
        if(index == n-1){
            return true;
        }
        return false;
    }
};