class MinStack {
public:
    stack<pair<int,int>> result;

    MinStack() {
        
    }
    
    void push(int val) {
        if(result.empty())
            result.push({val,val});

        else
            result.push({val,min(val,result.top().second)});    
    }
    
    void pop() {
        result.pop();
    }
    
    int top() {
        return result.top().first;
    }
    
    int getMin() {
        return result.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */