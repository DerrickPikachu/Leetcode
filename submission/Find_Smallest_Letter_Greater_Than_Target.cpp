class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int right,left,len,mid,t=0;
        len = letters.size();
        left = 0;
        right = len-1;
        
        while(left <= right) {
            mid = (left + right)/2;
            
            if (target > letters[mid]) 
                left = mid + 1;
            else if(target < letters[mid])
                right = mid - 1;
            else {
                while(letters[mid] == letters[mid+1]) {
                    mid++;
                }
                if (mid == len-1)
                    return letters[0];
                
                return letters[mid+1];
            }
        }
        
        
        if (left > len-1)
            return letters[0];
        return letters[left];
    }
};
