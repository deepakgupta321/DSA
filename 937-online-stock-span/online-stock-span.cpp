class StockSpanner {
    vector<int> prices; // Saare prices store karne ke liye
    stack<int> st;      // Indices store karne ke liye
    
public:
    StockSpanner() {
        // Constructor khali rahega
    }
    
    int next(int price) {
        prices.push_back(price);
        int currentIndex = prices.size() - 1;
        
        // Chote elements ke indices pop karo
        while (!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }
        
        int span;
        if (st.empty()) {
            // Agar koi bada element nahi bacha, toh span shuruwat tak jayega
            span = currentIndex + 1; 
        } else {
            // Agar pichla bada element mil gaya, toh unka difference span hoga
            span = currentIndex - st.top(); 
        }
        
        // Aaj ka index stack mein store kar lo aage ke liye
        st.push(currentIndex);
        
        return span;
    }
};