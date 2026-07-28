class Solution {
public:
    string smallestPalindrome(string s) {

        if(s.size()==1){
            return s;
        }


        vector<int> v(26,0);
        
        for(int i=0; i<s.size(); i++){
            v[s[i]-'a']++;
        }

        string ans="";

        int x=0;
        for(int i=0; i<26; i++){
            if(v[i]%2!=0){
                x=i;
                break;
            }
        }

        if(s.size()%2==0){
            for(int i=0; i<26; i++){
            if(v[i]>0){
                int len=v[i]/2;
                v[i]-=len;
                ans.append(len, i+'a');
            }  
        }
            string temp=ans;
            reverse(temp.begin(), temp.end());
            ans+=temp;
            return ans;
        }

        else{

        
        for(int i=0; i<26; i++){
    
            if(v[i]>0){
                int len=v[i]/2;
                v[i]-=len;
                ans.append(len, i+'a');
            }
        }
        string h=ans;
        reverse(h.begin(), h.end());
        ans.push_back(x+'a');
        ans+=h;
        
        return ans;
        }
        
       return ans;

    }
};