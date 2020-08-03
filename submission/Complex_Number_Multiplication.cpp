class Solution {
private:
    void getNum(string complex, int& num, int& com) {
        string tem;
        
        for (int i=0; i<complex.size()-1; i++) {
            if (complex[i] == '+') {
                num = stoi(tem);
                tem.clear();
            }
            else
                tem.push_back(complex[i]);
        }
        com = stoi(tem);
    }
public:
    string complexNumberMultiply(string a, string b) {
        int numA, comA, numB, comB, numRes, comRes;
        
        getNum(a, numA, comA);
        getNum(b, numB, comB);
        
        numRes = numA * numB - comA * comB;
        comRes = numB * comA + numA * comB;
        return to_string(numRes) + "+" + to_string(comRes) + "i";
    }
};
