class Solution {
public:
    long long minMoves(vector<int>& v) {
        
        long long sum = accumulate(v.begin(), v.end(), 0LL);
        long long move=0;
        int index=-1;

        for(int i=0; i<v.size(); i++){
            if(v[i]<0){
                index=i;
                break;
            }
        }
        
        if(sum<0 ){
            return -1;
        }

        if(index==-1){
            return 0;
        }

        else{
            int n=v.size();
            long long d=1;
            

            while(v[index]!=0){

                long long left=(index-d+n)%n;
                long long right=(index+d)%n;
                
                
                long long a=v[left]+v[right];

                if(left==right){
                    a=a-v[left];
                }

                long long temp=min(-1LL*v[index],a);
                v[index]+=temp;
                
                move+=temp*d;
                d++;
                
            }
        }
        return move;
    }
};