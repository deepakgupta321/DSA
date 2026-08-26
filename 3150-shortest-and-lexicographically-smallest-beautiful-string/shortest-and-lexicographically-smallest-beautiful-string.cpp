class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="";
        int i=0; 
        int j=0;
        int c=0;
        while(j<s.size()){
            if(s[j]=='1'){
                c++;
            }
            while(i<=j && c==k){
                if(ans==""){
                    ans=s.substr(i,j-i+1);
                }
                else if(j-i+1==ans.size()){
                    ans=min(ans, s.substr(i, j-i+1));
                }
                else if(ans.size()>j-i+1){
                    ans=s.substr(i,j-i+1);
                }
                if(s[i]=='1') c--;
                i++;

            }
            j++;
        }
        return ans;
    }
};