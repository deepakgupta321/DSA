class Solution {
public:
    int maxProduct(int n) {
        
        int x=INT_MIN;
        int y=INT_MIN;
        while(n!=0){
            int temp=n%10;
            n=n/10;
            if(x<temp){
                y=x;
                x=temp;
            }
            else if(temp>y){
                y=temp;
            }
        }

        return x*y;

    }
};