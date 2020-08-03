class TimeMap {
private:
    
    class TimeElement {
    public:
        string value;
        int timestamp;
        
        TimeElement(string v, int t) {
            value = v;
            timestamp = t;
        }
    };
    
    unordered_map<string, vector<TimeElement>> store;
    
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        TimeElement element(value, timestamp);
        store[key].push_back(element);
    }
    
    string get(string key, int timestamp) {
        if (store.count(key)) {
            for (int i=store[key].size()-1; i>=0; i--) {
                if (store[key][i].timestamp <= timestamp)
                    return store[key][i].value;
            }
        }
        
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
