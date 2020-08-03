class Solution {
private:
    class Fraction {
    public:
        int numerator, denominator;
        
        Fraction(int num, int deNum) {
            numerator = num;
            denominator = deNum;
        }
        
        void turnDenomTo(int target) {
            int times = target / denominator;
            denominator = target;
            numerator *= times;
        }
        
        void reduce() {
            int numGcd = gcd(numerator, denominator);
            numerator /= numGcd;
            denominator /= numGcd;
        }
        
        void operate(char op, Fraction other) {
            int denomLcm = denominator * other.denominator / gcd(denominator, other
                .denominator);
            turnDenomTo(denomLcm);
            other.turnDenomTo(denomLcm);
            
            if (op == '+')
                numerator += other.numerator;
            else
                numerator -= other.numerator;
            reduce();
        }
        
        string print() {
            return to_string(numerator) + "/" + to_string(denominator);
        }
    };
public:
    string fractionAddition(string expression) {
        bool negative = (expression[0] == '-')? true:false, isDivide = false;
        int i = (negative)? 1:0;
        string num, denom;
        Fraction res(0, 1);
        expression.push_back('+');
        
        for (; i<expression.size(); i++) {
            char cur = expression[i];
            
            if (cur != '/' && !isDivide && isdigit(cur))
                num.push_back(cur);
            else if (cur != '/' && isDivide && isdigit(cur))
                denom.push_back(cur);
            else if (cur == '/')
                isDivide = true;
            else {
                cout << num << " " << denom << endl;
                if (negative)
                    res.operate('-', Fraction(stoi(num), stoi(denom)));
                else
                    res.operate('+', Fraction(stoi(num), stoi(denom)));
                num.clear();
                denom.clear();
                isDivide = false;
                negative = (cur == '-')? true:false;
            }
        }
        
        return res.print();
    }
};
