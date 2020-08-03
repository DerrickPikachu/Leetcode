class Solution {
private:
    class Transaction{
    public:
        string name, city;
        int time, amount;
        
        Transaction(string& tran) {
            stringstream divide(tran);
            string n, t, a, c;
            
            getline(divide, n, ',');
            getline(divide, t, ',');
            getline(divide, a, ',');
            getline(divide, c, ',');
            
            name = n;
            time = stoi(t);
            amount = stoi(a);
            city = c;
        }
        
        string toString() {
            return name + "," + to_string(time) + "," + to_string(amount) + "," + 
                city;
        }
    };
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_set<string> invalid;
        vector<string> res;
        unordered_map<string, vector<int>> preTransaction;
        
        for (int i=0; i<transactions.size(); i++) {
            Transaction current(transactions[i]);
            
            if (preTransaction.count(current.name)) {
                vector<int> previous = preTransaction[current.name];

                for (int j=0; j<previous.size(); j++) {
                    Transaction tem(transactions[previous[j]]);

                    if (tem.city != current.city && abs(tem.time - current.time) <= 
                        60) {
                        // invalid
                        string pre = tem.toString(), cur = current.toString();

                        if (!invalid.count(cur)) {
                            invalid.insert(cur);
                            res.push_back(cur);
                        }
                        if (!invalid.count(pre)) {
                            invalid.insert(pre);
                            res.push_back(pre);
                        }
                    }
                }
            }
            
            if (current.amount > 1000 && !invalid.count(transactions[i])) {
                invalid.insert(current.toString());
                res.push_back(current.toString());
            }
            
            preTransaction[current.name].push_back(i);
        }
        
        return res;
    }
};
