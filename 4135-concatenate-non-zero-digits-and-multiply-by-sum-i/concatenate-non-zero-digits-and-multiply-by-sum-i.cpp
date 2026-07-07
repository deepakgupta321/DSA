class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0;
        while(n>0){
            int t=n%10;
            if(t>0){
                x=x*10;
                x=x+t;
            }
            n=n/10;
        }
        // reverse karne ke liya........
        long long k=0;
        while(x>0){
            k=k*10+x%10;
            x=x/10;
        }
        
        // calulating the sum assign new i=k;
        long long sum=0;
        long long i=k;
        while(i>0){
            sum=sum+i%10;
            i=i/10;
        }

        // long long j=sum*k;
        return sum*k;
    }
};