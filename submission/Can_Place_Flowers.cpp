class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.empty())  return false;
        if (n == 0) return true;
        int i,count=0,len;
        bool check=false;
        len = flowerbed.size();
        
        for (i=0;i<len;i++) {
            if (flowerbed[i] == 1) {
                i++;
                check = true;
                count--;
            }
            else if (flowerbed[i] == 0)
                count++;
            if (check == true || i == len-1) {
                if (count%2 == 0)
                    n -= count/2;
                else if (count%2 == 1)
                    n -= count/2+1;
                check = false;
                count = 0;
            }
        }
        
        // if (count != 0) {
        //     if (count%2 == 0)
        //         n -= count/2;
        //     else
        //         n -= count/2+1;
        // }
        return (n <= 0);
    }
};
