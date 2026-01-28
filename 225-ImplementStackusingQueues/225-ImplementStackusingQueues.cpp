// Last updated: 1/28/2026, 11:54:58 PM
1class MyStack {
2    queue<int> q1 ;
3    queue<int> q2 ;
4public:
5    MyStack() {
6        
7    }
8    
9    void push(int x) {
10        while(!q1.empty()){
11            q2.push(q1.front()) ;
12            q1.pop() ;
13        }
14        q1.push(x) ;
15        while(!q2.empty()){
16            q1.push(q2.front()) ;
17            q2.pop() ;
18        }
19    }
20    
21    int pop() {
22        int ans = q1.front() ;
23        q1.pop() ;
24        return ans ;
25    }
26    
27    int top() {
28        return q1.front() ;
29    }
30    
31    bool empty() {
32        return q1.empty() ;
33    }
34};
35
36/**
37 * Your MyStack object will be instantiated and called as such:
38 * MyStack* obj = new MyStack();
39 * obj->push(x);
40 * int param_2 = obj->pop();
41 * int param_3 = obj->top();
42 * bool param_4 = obj->empty();
43 */