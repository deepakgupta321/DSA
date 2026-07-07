class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push({value, value});
        }
        else{
            int m=min(st.top().second, value);
            st.push({value,m});
        }
    }
    
    void pop() {
        if(st.empty()){
            cout<<"INVALID";
        }
        else{
           st.pop();
        }
    }
    
    int top() {
        if(st.empty()){
            return NULL;
        }
        else{
            return st.top().first;
        }
    }
    
    int getMin() {
        if(st.empty()){
            return NULL;
        }
        else{
            return st.top().second;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */