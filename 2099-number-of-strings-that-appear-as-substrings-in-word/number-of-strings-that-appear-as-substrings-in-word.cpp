class Solution {
public:
        bool check(string str, string word){
            if(str.size()>word.size()){
                return false;
            }

            int c=0;
            int i=0; 
            int j=0;

            while(j<word.size() and str[i]!=word[j]){
                j++;
            }
                    
                
            while(i<str.size() and j<word.size()){
                if(str[i]==word[j]){
                    i++;
                    j++;
                    c++;
                }

                else{

                if(i<str.size() and j<word.size() ){
                    if(str[i]!=word[j]){
                        j = j - c + 1;
                        i=0;
                        c=0;
                    }
                    while(j<word.size() && str[i]!=word[j]){
                        j++;
                    }
                }

                }
            }
            if(c==str.size()){
                return true;
            }
            else{
                return false;
            }
        }


    int numOfStrings(vector<string>& patterns, string word) {
        

         int count=0;
        for(int i=0; i<patterns.size(); i++){
            bool v=check(patterns[i], word);
            if(v==true){
                count++;
            }
        }

        return count;
    }
};