class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> m;
        int i=0;
        int j=0;
        int ans=0;

        while(j<s.size()){
            m[s[j]]++;

            while(m.contains(s[j])){
                if(i<=j && m[s[j]]>2){

                 
                m[s[i]]--;
                i++;
                   
                  
                }
                else break;
            }
          ans=max(ans, j-i+1);
          j++;

        }

        return ans;


    }
};