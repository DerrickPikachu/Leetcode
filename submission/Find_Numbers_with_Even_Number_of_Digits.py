class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        res = 0
        
        for num in nums:
            tem = num
            count = 0
            divider = 1
            
            while tem // divider != 0:
                divider *= 10
                count += 1
            print(count)
            if count % 2 == 0:
                res += 1
        
        return res
