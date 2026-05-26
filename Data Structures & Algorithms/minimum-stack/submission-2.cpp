class MinStack {
public:
    MinStack() {
        
    }
    stack<int> s;
    stack<int> mins;
    void push(int val) {
        s.push(val);
        if(mins.empty())
        mins.push(val);
        else if(mins.top()>=val)
        mins.push(val);
    }
    
    void pop() {
        if(!mins.empty()&&mins.top()==s.top())
        mins.pop();

        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
