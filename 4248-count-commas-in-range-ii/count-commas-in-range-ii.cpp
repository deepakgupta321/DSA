class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        long long ans=0;
        if(n<999999) return n-999;
        
        
        if(n<999999999){
            long long x=n-999999;
            x=2*x;
            
            return (999999-999) + x;
        }
        if(n<999999999999){
            long long x=n-999999999;
            x=3*x;

            return (999999-999) +2*(999999999-999999)+x;
        }
        if(n<999999999999999){
            long long x=n-999999999999LL;
            x=4*x;
            return (999999-999) +2*(999999999-999999)+3*(999999999999-999999999)+x;
            
        }
        else{
            long long x=n-999999999999999;
            x=5*x;
            return (999999-999) +2*(999999999-999999)+3*(999999999999-999999999)+4*(999999999999999-999999999999)+x;
        }

    }
};