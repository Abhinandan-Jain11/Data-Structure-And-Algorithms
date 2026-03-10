class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> words;
        stringstream ss(s);
        string temp;
        while(ss>>temp){
            words.push_back(temp);
        }
        int n = words.size();
        string last = words[n-1];
        return last.size();
    }
};