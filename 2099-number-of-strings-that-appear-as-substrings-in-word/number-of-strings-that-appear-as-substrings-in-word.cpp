class Solution {
public:
    bool check(string s, vector<string> v){
            for(int i=0; i<v.size(); i++){
                if(v[i]==s){
                    return true;
                }
            }
            return false;
        }

    int numOfStrings(vector<string>& patterns, string word) {

        vector<string> v;
        for(int i=0; i<word.size(); i++){
            string temp="";
            for(int j=i; j<word.size(); j++){
                temp=temp+word[j];
                v.push_back(temp);
            }
        }
        
        

        int count=0;
        for(int i=0; i<patterns.size(); i++){
            bool y=check(patterns[i], v);
            if(y==true){
                count++;
            }
        }

        return count;
        
    }
};