class Solution {
private:
    int numOfPrimes(int n) {
        vector<int> num(n+1, 0);
        int res = 0;
        
        for (int i=2; i<=n; i++) {
            if (num[i] == 0) {
                res++;
                for (int j=2; j*i<=n; j++)
                    num[j*i] = 1;
            }
        }
        
        return res;
    }
public:
    int numPrimeArrangements(int n) {
        long int primes = numOfPrimes(n);
        long int normalNums = n - primes, resInNormal = 1, resInPrime = 1;
        int res;
        
        for (; primes>=1; primes--)
            resInPrime = (resInPrime * primes) % 1000000007;
        
        for (; normalNums>=1; normalNums--)
            resInNormal = (resInNormal * normalNums) % 1000000007;
        
        res = (resInPrime * resInNormal) % 1000000007;
        return res;
    }
};
