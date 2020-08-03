from operator import itemgetter, attrgetter
class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        count = []
        res = []
        
        for row in mat:
            soldiers = [0] * 2;
            soldiers[0] = len(count)
            for entry in row:
                soldiers[1] += entry
            count.append(soldiers)
            
        sortedCount = sorted(count, key = itemgetter(1, 0))
        
        for row in sortedCount:
            if len(res) >= k:
                break
            res.append(row[0])
        return res
