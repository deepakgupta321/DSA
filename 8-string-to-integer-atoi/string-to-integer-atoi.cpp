class Solution {
public:
    int myAtoi(string s) {
        int ans=0;
        int neg=0;
        int pos=0;
        int i=0;

        while(i<s.size() && s[i]==' '){
            i++;
        }
        if(s[i]>57){
            return 0;
        }
        while(i<s.size() && (s[i]=='-' or s[i]=='+')){
            if(s[i]=='-'){
                neg++;
            }    
            else{
                pos++;
            }
            if(neg>1){
                return 0;
            } 
            if(pos>1){
                return 0;
            }
            i++;
        }
        if(pos==1 and neg==1 ){
            return 0;
        }
        
        
        while(i<s.size()){
            if(s[i]>57  or s[i]<48){
                if(neg==1){
                    return -ans;
                }
                return ans;
            }
            else if(s[i]<=57 && s[i]>=48){
                if((long long)ans*10+s[i]-'0'>INT_MAX){
                    if(neg==1){
                        return INT_MIN;
                    }
                    else{
                        return INT_MAX;
                    }
                }
                else{
                    ans=ans*10+ (s[i]-'0');
                }
                
            }
            i++;
        }

        if(neg==1)
            return -ans;
        return ans;
    }
};