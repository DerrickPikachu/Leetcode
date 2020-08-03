class Solution:
    def maximum69Number (self, num: int) -> int:
        position = 10 ** 4
        
        while position != 0:
            if (num // position) % 10 == 6:
                num += 3 * position
                break
            position //= 10
        
        return num
