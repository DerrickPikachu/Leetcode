class CustomStack {
private:
    vector<int> myStack;
    int maxSize;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (myStack.size() < maxSize)
            myStack.push_back(x);
    }
    
    int pop() {
        int res = -1;
        if (!myStack.empty()) {
            res = myStack.back();
            myStack.pop_back();
        }
        return res;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < k && i < myStack.size(); i++)
            myStack[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
