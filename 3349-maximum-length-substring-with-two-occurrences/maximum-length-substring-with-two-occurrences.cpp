class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int,int> m;
        int i=0;
        int j=0;
        int ans=0;

        while(j<s.size()){
            m[s[j]]++;

            while(m[s[j]]>2){
                if(m[s[i]]>0)
                  m[s[i]]--;
                i++;
            }
          ans=max(ans, j-i+1);
          j++;

        }

        return ans;


    }
};