class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if(mn.empty() || mn.top() >= x) mn.push(x);
    }
    
    void pop() {
        if(st.empty()) return;
        if(st.top() == mn.top()) mn.pop();
        st.pop();
        return;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mn.top();
    }
private:
    std::stack<int> st;
    std::stack<int>mn;
};

