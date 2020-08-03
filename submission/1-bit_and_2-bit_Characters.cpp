class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int len=bits.size(),i;
        
        for (i=0;i<len;i++) {
            if (bits[i] == 1) {
                i = i+1;
                if (i+1 == len)    return false;
            }
        }
        return true;
    }
};
