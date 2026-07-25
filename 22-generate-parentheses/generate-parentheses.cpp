class Solution {
public:
     bool isValid(string &s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '(') {
                st.push(ch);
            } else {
                if (st.empty())
                    return false;
                st.pop();
            }
        }

        return st.empty();
     }
    void gp(vector<string>& ans, string &temp, int i, int j, int &n){
        if(i==n && j==n){
            if(isValid(temp)){
                ans.push_back(temp);
               return;
            }
            
        }
        if(i+j==2*n){
            return;
        }
        
       
            temp.push_back('(');
            gp(ans,temp, i+1, j,n);
            temp.pop_back(); // pop kuch or explore karna tha


            // backtrack
            temp.push_back(')');
            gp(ans,temp,i, j+1,n);
            temp.pop_back();
        
        
        
        

        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int i=0;
        int j=0;
        string temp="";
        gp(ans, temp, i, j,n);
        return ans;
    }
};