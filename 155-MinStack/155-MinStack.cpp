// Last updated: 11/2/2025, 10:33:29 PM
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>s;
    stack<int>min_val;//vector to store min values
    MinStack() {


    }
    
    void push(int val) {
        s.push(val);
        if(min_val.empty() || val<=getMin())
        {
            min_val.push(val);
        }
    }
    
    void pop() {
        if(s.top() == getMin())
        {
            min_val.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_val.top(); //top value is the min value of the stack
        }
        
};
//["MinStack","push","push","push","getMin","pop","getMin"]

//["MinStack","push","push","push","push","getMin","pop","getMin","pop","getMin","pop","getMin"]
//stack : 2 - 0 - 3 - 0 - 0(getmin) - 
//minstack : 2/0/0/0
//[[],[2],[0],[3],[0],[],[],[],[],[],[],[]]
//[null,null,null,null,null,0,null,0,null,0,null,0]
//[null,null,null,null,null,0,null,0,null,0,null,2]
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */