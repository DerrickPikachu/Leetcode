class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int length = deck.size()-1, lastIndex = deck.size();
        
        for (int i = 1; i < (length + 1) * 2 - 2; i += 2)
            deck.insert(deck.begin() + i, 0);
        
        for (int i = 1; i < deck.size() - 1; i += 2) {
            if (lastIndex % 2 != 0)
                deck[lastIndex] = i;
            else {
                int back = i;
                while(back > length)
                    back = deck[back];
                deck[back] = deck[lastIndex];
            }
            lastIndex++;
        }
        
        vector<int> res(deck.begin(), deck.begin() + length + 1);
        
        return res;
    }
};
