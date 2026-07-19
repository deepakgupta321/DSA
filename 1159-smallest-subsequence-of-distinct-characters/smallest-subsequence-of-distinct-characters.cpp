class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> v(256,0);
        vector<int> used(256,0);

        for(int i=0; i<s.size(); i++){
            v[s[i]]++;
        }

        string ans="";
        stack<char> st;

        for(int i=0; i<s.size(); i++){

            if(used[s[i]]==1){
                v[s[i]]--;
                continue;
            }

            while(!st.empty()  && st.top()>s[i] && v[st.top()]>1){

                used[st.top()]=0;
                v[st.top()]--;
                st.pop();
                      
            }

            
            st.push(s[i]);
            used[s[i]]=1;
            
        }
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;




    }
};