class Solution {
private:
    void track(int& res, vector<int>& arrange, int index, int N, unordered_set<int>& 
        appeared) {
        int pos = index + 1;
        
        if (index == N) {
            res++;
            return;
        }
        
        for (int i=1; i<=N; i++) {
            if (!appeared.count(i)) {
                if (pos % i == 0 || i % pos == 0) {
                    arrange[index] = i;
                    appeared.insert(i);
                    
                    track(res, arrange, index + 1, N, appeared);
                    
                    arrange[index] = 0;
                    appeared.erase(i);
                }
            }
        }
    }
public:
    int countArrangement(int N) {
        int res = 0;
        vector<int> arrange(N, 0);
        unordered_set<int> appeared;
        track(res, arrange, 0, N, appeared);
        return res;
    }
};
