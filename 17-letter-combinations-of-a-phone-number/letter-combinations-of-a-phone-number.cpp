class Solution {
public:
    void cp(vector<string> &ans, string &temp, int i, string &s, unordered_map<char,string> &m){
        if(temp.size()==s.size()){
            ans.push_back(temp);
            return;
        }

        string choice=m[s[i]];
        for(int j=0; j<choice.size(); j++){
            temp.push_back(choice[j]);
            cp(ans, temp, i+1, s, m);
            temp.pop_back();
        }
    }


    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";

        vector<string> ans;
        string temp;
        int i=0;
        cp(ans,temp,i,digits,m);
        return ans;
    }
};