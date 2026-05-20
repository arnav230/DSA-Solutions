class StockSpanner {
public:
    stack<pair<int,int>> st;
    int i = -1;

    StockSpanner() {
    }
    int next(int price) {
        i++;     
        while(!st.empty() && st.top().first <= price) {
            st.pop();
        }   
        int span;   
        if(st.empty()) {
            span = i + 1;
        } else {
            span = i - st.top().second;
        }
        st.push({price, i});
        return span;
    }
};
