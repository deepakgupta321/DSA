class Solution {
public:
    int minAddToMakeValid(string s) {
        int left=0;
        int ans=0;
        for(int i=0;i<s.size(); i++){
            if(s[i]=='('){
                left++;
            }
            else if(left==0){
                ans++;
            }
            else{
                left--;
            }
        }

        return ans+left;
    }
};