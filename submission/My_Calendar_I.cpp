class MyCalendar {
private:
    class interval {
    public:
        int start, end;
        
        interval(int s, int e) {
            start = s;
            end = e;
        }
    };
    
    vector<interval> startTime;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        interval section(start, end);
        int i;
        
        if (startTime.empty()) {
            startTime.push_back(section);
            return true;
        }
        
        for (i=0; i<startTime.size(); i++) {
            
            if (startTime[i].start > start) {
                if (end <= startTime[i].start) {
                    if (i != 0 && startTime[i-1].end > start)
                        return false;
                    startTime.insert(startTime.begin() + i, section);
                    break;
                }
                else
                    return false;
            }
        }
        if (i == startTime.size()) {
            if (i != 0 && startTime[i-1].end > start)
                return false;
            startTime.insert(startTime.begin() + i, section);
        }
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
