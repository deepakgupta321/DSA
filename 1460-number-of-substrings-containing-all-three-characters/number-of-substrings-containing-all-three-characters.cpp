class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> m;
        int i=0; 
        int j=0;

        int count=0;
        while(j<s.size()){
            m[s[j]]++;
            while(m.size()==3){
                count++;
                count=count+s.size()-j-1;
                m[s[i]]--;
                if(m[s[i]]==0){
                    char g=s[i];
                    m.erase(g);
                }
                i++;
                
            }
            j++;
        }

        return count;
    }
};