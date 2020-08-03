class BrowserHistory {
private:
    class ListNode {
    public:
        string url;
        ListNode* next;
        ListNode* back;
    
        ListNode(string url) {
            this->url = url;
            next = NULL;
            back = NULL;
        }
    };
    
    ListNode* head;
    ListNode* current;
    
public:
    BrowserHistory(string homepage) {
        head = new ListNode(homepage);
        current = head;
    }
    
    void visit(string url) {
        current->next = new ListNode(url);
        current->next->back = current;
        current = current->next;
    }
    
    string back(int steps) {
        while (current->back != NULL && steps != 0) {
            current = current->back;
            steps--;
        }
        
        return current->url;
    }
    
    string forward(int steps) {
        while (current->next != NULL && steps != 0) {
            current = current->next;
            steps--;
        }
        
        return current->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
