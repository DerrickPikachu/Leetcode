class Solution {
private:
    int getDiff(string a, string b) {
        string ma, mb, ha, hb;
        int haVal, maVal, hbVal, mbVal, diff = 0;
        ha = a.substr(0, 2);
        ma = a.substr(3, 2);
        hb = b.substr(0, 2);
        mb = b.substr(3, 2);
        
        haVal = stoi(ha);
        maVal = stoi(ma);
        hbVal = stoi(hb);
        mbVal = stoi(mb);
        
        if (haVal > hbVal) {
            diff = maVal + 60 - mbVal + (haVal - hbVal - 1) * 60;
        }
        else if (haVal < hbVal) {
            diff = maVal + 60 - mbVal + (haVal + 23 - hbVal) * 60;
        }
        else {
            if (maVal >= mbVal)
                diff = maVal - mbVal;
            else
                diff = 24 * 60 - abs(maVal - mbVal);
        }
        
        return diff;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        cout << "FDSAFDSA" << endl;
        sort(timePoints.begin(), timePoints.end());
        int res = INT_MAX;
        
        cout << "eiwotot" << endl;
        
        for (int i=0; i<timePoints.size(); i++) {
            cout << timePoints[i] << endl;
            if (i == 0)
                res = min(res, getDiff(timePoints[i], timePoints.back()));
            else
                res = min(res, getDiff(timePoints[i], timePoints[i-1]));
        }
        
        return res;
    }
};

