class Solution {
public:
    int minimumPushes(string word) {
        if(word.size()<=8){
            return word.size();
        }

        else if(word.size()<=16){
            int x=word.size()-8;
            return 8+x*2;
        }

        else if(word.size()<=24){
            int x=word.size()-16;

            return 8+16+x*3;
        }
        else if(word.size()>24){
            int x=word.size()-24;
            return 8+16+24+x*4;
        }

        return 1;
    }
};