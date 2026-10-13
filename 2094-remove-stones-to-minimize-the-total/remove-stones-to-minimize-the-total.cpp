class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        for (auto x: piles){
            q.push(x);
        }
        while(k--){
            int x=q.top()-q.top()/2;
            q.pop();
            q.push(x);
        }
        int ans=0;
        while(!q.empty()){
            ans+=q.top();
            q.pop();
        } 
        return ans;
    }
};