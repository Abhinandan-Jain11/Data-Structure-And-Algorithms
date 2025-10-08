class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());
        vector<int> pairs;
        for(int i=0; i<n; i++){
            long long minPotion = (success + (long long)spells[i] - 1)/spells[i];
            int index = lower_bound(potions.begin(),potions.end(),minPotion)- potions.begin();
            pairs.push_back(m - index);
        }
        return pairs;
    }
};