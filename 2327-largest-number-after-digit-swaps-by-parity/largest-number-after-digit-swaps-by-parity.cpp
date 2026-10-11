class Solution {
public:
    int largestInteger(int num) {
        if(num<=11){
            return num;
        }
        priority_queue<int> even;
        priority_queue<int> odd;
        int num2=num;
        while(num2!=0){
            int x=num2%10;
            num2=num2/10;
            if(x%2==0){
                even.push(x);
            }
            else{
                odd.push(x);
            }
        }
        string s=to_string(num);
        int ans=0;
        for(int i=0; i<s.size(); i++){
            int temp=s[i]-'0';
            if(temp%2==0){
                ans=ans*10+even.top();
                even.pop();
            }
            else{
                ans=ans*10+odd.top();
                odd.pop();
            }
        }
        return ans;



        




    }
};