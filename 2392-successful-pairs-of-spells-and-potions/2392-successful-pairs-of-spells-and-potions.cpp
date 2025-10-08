class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());
        vector<int> pairs;
        int i=0;
        while(i<n){
            int cnt = 0;
            int low = 0;
            int high = m-1;
            while(low<=high){
                int mid = (low+high)/2;
                if((long long)spells[i]*potions[mid] >= success){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            cnt = m-low;
            pairs.push_back(cnt);
            i++;
        }
        return pairs;
    }
};