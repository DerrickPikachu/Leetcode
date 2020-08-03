class MyQueue;

class Node{
private:
    int val;
    Node* next;
friend MyQueue;
};

class MyQueue {
private:
    Node* head;
    Node* last;
    bool isEmpty() {
        if(head == NULL)
            return true;
        return false;
    }
public:
    /** Initialize your data structure here. */
    MyQueue() {
        head = NULL;
        last = NULL;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (isEmpty()) {
            head = new Node;
            head->val = x;
            head->next = NULL;
            last = head;
        }
        else {
            last->next = new Node;
            last = last->next;
            last->val = x;
            last->next = NULL;
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        Node* p = head;
        int num;
        head = head->next;
        num = p->val;
        delete p;
        return num;
    }
    
    /** Get the front element. */
    int peek() {
        return head->val;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (head == NULL)? true:false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
