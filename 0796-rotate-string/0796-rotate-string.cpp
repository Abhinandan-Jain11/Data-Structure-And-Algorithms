class Solution {
public:
    void rotateAnticlockwise(string &s){
        char ch = s[0];
        int index = 1;
        while(index<s.size()){
            s[index-1] = s[index];
            index++;
        }
        s[s.size()-1] = ch;
    }
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string anticlockwise = s;
        for(int i=0; i<s.size(); i++){
            rotateAnticlockwise(anticlockwise);
            if(anticlockwise == goal){
                return true;
            }
        }
        return false;
    }
};