class Solution {
public:
    vector<int> validSequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        if (m > n) return {};

        // match[i] stores the maximum length of a valid subsequence 
        // of s2 that can be formed using the suffix s1[i...n-1]
        vector<int> match(n + 1, 0); 
        
        int j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && s1[i] == s2[j]) {
                match[i] = match[i + 1] + 1;
                j--;
            } else {
                match[i] = match[i + 1];
            }
        }

        vector<int> ans;
        bool power = false;
        int l = 0; // pointer for s2
        int k=0;

        while(k<n && ans.size()<m){
            if(s1[k]==s2[l]){
                ans.push_back(k);
                k++;
                l++;
            }
            else if(power==false && m-ans.size()-1<=match[k+1]){
                ans.push_back(k);
                k++;
                l++;
                power=true;
            }
            else{
                k++;
            }
        }

        if (ans.size() == m) {
            return ans;
        }
        
        return {};
    }
};