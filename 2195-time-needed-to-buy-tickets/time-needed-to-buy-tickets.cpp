class Solution {
public:
    int timeRequiredToBuy(vector<int>& arr, int k) {
        queue<int> q;

        for(int i=0; i<arr.size(); i++){
            q.push(i);
        }

        int time=0;
        while(arr[k]!=0){
            arr[q.front()]--;
            
            if(arr[q.front()]){
                q.push(q.front());
               
            }
            
            time++;
            q.pop();
        }

        return time;
    }
};