class Solution {
private:
    char rotating(char num) {
        if (num == '0' || num == '1' || num == '8')
            return num;
        else if (num == '2')
            return '5';
        else if (num == '5')
            return '2';
        else if (num == '6')
            return '9';
        else if (num == '9')
            return '6';
        
        return 'n';
        
    }
    
public:
    int rotatedDigits(int N) {
        int count = 0;
        
        for (int i=1; i<=N; i++) {
            string num = to_string(i);
            string tem = num;
            bool valid = true;
            
            for (int j=0; j<num.size(); j++) {
                char decision = rotating(num[j]);
                
                if (decision == 'n') {
                    valid = false;
                    break;
                }
                
                num[j] = decision;
                if (j == num.size() - 1)
                    count++;
            }
            
            if (tem == num && valid)
                count--;
        }
        
        return count;
    }
};
