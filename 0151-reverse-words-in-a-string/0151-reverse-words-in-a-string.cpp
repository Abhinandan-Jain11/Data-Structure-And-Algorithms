class Solution {
public:
    string reverseWords(string s) {
      stringstream ss(s);
      vector<string> words;
      string word;
      while(ss>>word){
        words.push_back(word);
      }
      s.clear();
      int n = words.size();
      for(int i=n-1; i>0; i--){
        s += words[i];
        s += " ";
      }
      s += words[0];
      return s;
    }
};