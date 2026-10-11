class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p(stones.begin(), stones.end());
        while(p.size()>1){
            int x1=p.top();
            p.pop();
            int x2=p.top();
            p.pop();
            if(x1!=x2){
                p.push(x1-x2);
            }
        }
        if(p.empty()){
            return 0;
        }
        return p.top();
    }
};