class Solution {
public:
    int timeRequiredToBuy(vector<int>& arr, int k) {
        queue<int> q;

        for(int i=0; i<arr.size(); i++){
            q.push(i);
        }

        int time=0;
        while(arr[k]!=0){
            int x=q.front();
            if(arr[x]==1){
                time+=1;
                arr[x]=arr[x]-1;
                q.pop();
            }
            else{
                time++;
                arr[x]=arr[x]-1;
                q.push(x);
                q.pop();
            }
        }

        return time;
    }
};