class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int size=0;
        int l=0;
        bool x=false;
        for(int i=0; i<s.size(); i++){
        
            if(s[i]=='('){

                l++;
                
            }
    
            else{
                l--;
            }

            if(size==0){
                size++;
                continue;
            }
            if(l==0){
                size=0;
                continue;
            }
            if(l>=1){
                ans+=s[i];
            }


        }
        return ans;
    }
};