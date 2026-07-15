class Solution {
public:

    int gcd(int x, int y){
        if(y==0){
            return x;
        }

        return gcd(y, x%y);
    }
    
    int gcdOfOddEvenSums(int n) {
        int even=2;
        int odd=1;
        
        int temp=2;
        int temp1=1;
        for(int i=0; i<n-1; i++){

            even+=temp+2;
            temp=temp+2;

            odd+=temp1+2;
            temp1=temp1+2;
        }

        int x=gcd(odd, even);
        return x;
    }
};