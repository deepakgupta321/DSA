class Solution {
public:
    bool checkDivisibility(int n) {
        int x=0;
        int y=1;
        int b=n;

        while(n){
            x+=n%10;
            y*=n%10;
            n=n/10;
        }
        
        if(b%(x+y)==0){
            return true;
        }
        return false;
    }
};