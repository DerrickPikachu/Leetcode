class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        res = [None] * 2
        res[0] = 1
        res[1] = n - res[0]
        divider = 1
        
        while res[1] // divider >= 10:
            currentNum = (res[1] // divider) % 10
            transform = 0
            
            if currentNum != 1:
                transform = divider
            else:
                transform = divider * 2
            
            res[1] -= transform
            res[0] += transform
            
            divider *= 10
        
        return res
