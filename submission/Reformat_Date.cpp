class Solution {
public:
    string reformatDate(string date) {
        vector<string> tokens, month = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        unordered_map<string, string> monthNum;
        stringstream date_(date);
        string tem, res;
        
        for (int i = 0; i < month.size(); i++) {
            if (i + 1 < 10)
                monthNum[month[i]] = "0" + to_string(i + 1);
            else
                monthNum[month[i]] = to_string(i + 1);
        }
        
        while (getline(date_, tem, ' '))
            tokens.push_back(tem);
        
        res = tokens[2] + "-" + monthNum[tokens[1]] + "-";
        if (tokens[0].size() == 3)
            res += "0" + tokens[0].substr(0, 1);
        else
            res += tokens[0].substr(0, 2);
        
        return res;
    }
};
