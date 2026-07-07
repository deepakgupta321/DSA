class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i=0; i<s.size(); i++){
            if(st.empty()){
                st.push({s[i], 1});
            }
            else if(st.top().first!=s[i]){
                st.push({s[i],1});
            }
            
            else if(st.top().first==s[i]){
               if(st.top().second!=k-1){
                  pair<char,int> p=st.top();
                  st.pop();
                  st.push({p.first, p.second+1});
               }
               else{
                st.pop();
               }
            }
        }
        string ans="";
        while(!st.empty()){
            ans.append(st.top().second, st.top().first);
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};