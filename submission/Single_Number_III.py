class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        count = {}
        res = list()
        
        for i in nums:
            if i in count:
                count[i] += 1
            else:
                count[i] = 1
        
        for key, appear in count.items():
            if appear == 1:
                res.append(key)
        
        return res
