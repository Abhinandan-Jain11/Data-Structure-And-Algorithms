class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        stack<char> st;
        for(int i=0; i<n; i++){
            st.push(s[i]);
        }
        s.clear();
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
    }
};