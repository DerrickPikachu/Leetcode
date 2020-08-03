class Solution {
public:
    
    uint32_t reverseBits(uint32_t n) {
        int i,shift;
        uint32_t save=0,get=1;
        for (i=0;i<32;i++) {
            if ((n & get) > 0) {
                if (i > 15){
                   shift = (i-15)*2-1;
                   get = get >> shift;
                
                }
                else{
                   shift = (32-i) - (i+1);
                   get = get << shift;
                }
                save += get;
                get = 1;
                get = get << (i+1);
            }
            else 
                get = get << 1;
        }
        return save;
    }
};
