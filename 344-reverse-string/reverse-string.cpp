class Solution {
public:
    void reverseString(vector<char>& s) {
        //2 pointer se logn and o(1) extra mai ho jayega

        // using stack

        stack<char> st;
        for(int i=0; i<s.size(); i++){
            st.push(s[i]);
        }
        int i=0;
        while(!st.empty()){
            s[i]=st.top();
            st.pop();
            i++;
        }
    }
};