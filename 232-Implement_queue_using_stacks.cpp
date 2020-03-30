Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Example:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false
Notes:

You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

// Use a back up stacki to staore all elements from s in reversed sequence when pop() and peek() happens.
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // moves all elements into the backup stack.
        while(!s.empty()) {
            s_backup.push(s.top());
            s.pop();
        }
        int res = s_backup.top();
        s_backup.pop();
        // moves all elements back to s.
        while(!s_backup.empty()) {
            s.push(s_backup.top());
            s_backup.pop();
        }
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        // moves all elements into the backup stack.
        while(!s.empty()) {
            s_backup.push(s.top());
            s.pop();
        }
        int res = s_backup.top();
        // moves all elements back to s.
        while(!s_backup.empty()) {
            s.push(s_backup.top());
            s_backup.pop();
        }
        return res;        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
private:
    stack<int> s;
    stack<int> s_backup;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
