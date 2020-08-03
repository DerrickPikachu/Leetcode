class UndergroundSystem {
    unordered_map<string, unordered_map<string, pair<int, double>>> record;
    unordered_map<int, pair<int, string>> startRecord;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        startRecord[id] = pair<int, string>(t, stationName);
    }
    
    void checkOut(int id, string stationName, int t) {
        string from = startRecord[id].second;
        string to = stationName;
        int fromt = startRecord[id].first;
        int tot = t;
        record[from][to].second = (record[from][to].first * record[from][to].second + 
            tot - fromt) / (record[from][to].first + 1);
        record[from][to].first++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return record[startStation][endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
