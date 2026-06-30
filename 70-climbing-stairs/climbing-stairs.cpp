class Solution {
public:
    // int fn(int n){
    //     if(n==1 or n==2){
    //         return n;
    //     }
    //     return fn(n-1)+fn(n-2);
    // }
    int climbStairs(int n) {
        int a=1;
        int b=2;
        if(n==1 or n==2){
            return n;
        }
        int result=0;
        int x=2;
        while(x<n){
            result=a+b;
            a=b;
            b=result;
            x++;
        }

        return result;
    }
};