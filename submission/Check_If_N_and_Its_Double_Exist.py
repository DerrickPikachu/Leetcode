class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        exist = []
        zeroCount = 0
        for num in arr:
            exist.append(num)
        
        for num in arr:
            if num // 2 in exist and num % 2 == 0 and num != 0:
                return True
            if num == 0:
                if zeroCount > 0:
                    return True
                zeroCount += 1
        
        return False
