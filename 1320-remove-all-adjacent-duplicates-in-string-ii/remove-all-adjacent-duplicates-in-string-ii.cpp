class Solution {
public:
    string removeDuplicates(string s, int k) {
        // stack<pair<char,int>> st;  badhiya approach hai
        // for(int i=0; i<s.size(); i++){
        //     if(st.empty()){
        //         st.push({s[i], 1});
        //     }
        //     else if(st.top().first!=s[i]){
        //         st.push({s[i],1});
        //     }
            
        //     else if(st.top().first==s[i]){
        //        if(st.top().second!=k-1){
        //           pair<char,int> p=st.top();
        //           st.pop();
        //           st.push({p.first, p.second+1});
        //        }
        //        else{
        //         st.pop();
        //        }
        //     }
        // }
        // string ans="";
        // while(!st.empty()){
        //     ans.append(st.top().second, st.top().first);
        //     st.pop();
        // }

        // reverse(ans.begin(), ans.end());
        // return ans;

        stack<pair<char,int>> st;
        
        for(int i = 0; i < s.size(); i++){
            // Agar stack khali hai ya naya character aaya hai, toh push karo count = 1
            if(st.empty() || st.top().first != s[i]){
                st.push({s[i], 1});
            }
            // Agar same character mil gaya
            else {
                st.top().second++; // Sirf existing pair ka count badhao
                
                // Agar count 'k' ke equal ho gaya, toh usko stack se uda do
                if(st.top().second == k){
                    st.pop();
                }
            }
        }
        
        string ans = "";
        // FIX: !st.empty() hona chahiye
        while(!st.empty()){
            // FIX: append takes (count, char)
            ans.append(st.top().second, st.top().first); 
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};