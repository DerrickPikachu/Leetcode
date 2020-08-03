class MapSum {
private:
    unordered_map<string, int> mp;
    unordered_set<string> st;
public:
    /** Initialize your data structure here. */
    MapSum() {
        mp.clear();
    }
    
    void insert(string key, int val) {
        string tem = "";
        
        if (st.count(key)) {
            val -= mp[key];
        }
        else {
            st.insert(key);
         }
        
        for (int i=0; i<key.size(); i++) {
            tem.push_back(key[i]);
            mp[tem] += val;
        }
    }
    
    int sum(string prefix) {
        return (mp.count(prefix))? mp[prefix]:0;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
