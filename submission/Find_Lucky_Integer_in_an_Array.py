class Solution:
    def findLucky(self, arr: List[int]) -> int:
        counter = {}
        res = -1
        
        for value in arr:
            if value in counter:
                counter[value] += 1
            else:
                counter[value] = 1
        
        for key, freq in counter.items():
            if key == freq:
                res = max(res, key)
        return res
