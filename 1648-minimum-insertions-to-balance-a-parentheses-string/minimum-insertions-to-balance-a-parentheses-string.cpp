class Solution {
public:
    int minInsertions(string s) {
        int ans=0;
        int open=0;
        for(int i=0; i<s.size(); i++){
            if(open==0 && s[i]==')'){
                ans++;
                open++;
            }
            if(s[i]=='('){
                open++;
            }
            else{
                if(open>0){
                    if(s[i+1]==')'){
                        i++;
                        open--;
                    }
                    else{
                        ans++;
                        open--;
                    }
                }
                else{
                    ans++;
                }
            }
        }
        ans=ans+open*2;
        return ans;
    }
};