class Solution {
private:
    string encode(int n) {
        vector<int> bucket(10, 0);
        string key;
        while (n != 0) {
            int digit = n % 10;
            n /= 10;
            bucket[digit]++;
        }
        
        for (int i=0; i<bucket.size(); i++)
            key.insert(key.end(), bucket[i], i + '0');
        return key;
    }
public:
    bool reorderedPowerOf2(int N) {
        int power = 0, limit = pow(10, 9), powerOfTwo = 1;
        unordered_set<string> keys;
        
        while (powerOfTwo < limit) {
            string key = encode(powerOfTwo);
            keys.insert(key);
            powerOfTwo = pow(2, ++power);
        }
        
        return keys.count(encode(N));
    }
};
