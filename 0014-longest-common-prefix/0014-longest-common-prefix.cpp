class Solution {
public:

    string findCommon(string &ans, string str){
        int size = min(ans.size(),str.size());
        int i=0;
        if(ans.size()<=str.size()){
            while(!ans.empty() && i<size){
                if(ans[i] != str[i]){
                    if(i==0){
                        ans = "";
                        break;
                    }else{
                        ans = ans.substr(0,i);
                    break;
                    }
                }
                i++;
            }
        }else{
            ans = ans.substr(0,size);
            while(!ans.empty() && i<size){
                if(ans[i] != str[i]){
                    if(i==0){
                        ans = "";
                        break;
                    }else{
                        ans = ans.substr(0,i);
                    break;
                    }
                }
                i++;
            }
        }
        
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i=1; i<strs.size(); i++){
            ans = findCommon(ans,strs[i]);
        }
        return ans;
    }
};