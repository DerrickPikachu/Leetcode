class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        left = [0] * len(seats)
        right = [0] * len(seats)
        counter = 0
        res = -1
        
        for seat in range(len(seats)):
            counter += 1
            if seats[seat] == 1:
                counter = 0
            left[seat] = counter
            
        counter = 0
        for seat in range(len(seats) - 1, -1, -1):
            counter += 1
            if seats[seat] == 1:
                counter = 0
            right[seat] = counter
            
        for i in range(len(seats)):
            if i == 0:
                res = max(right[i], res)
            elif i == (len(seats) - 1):
                res = max(left[i], res)
            else:
                res = max(min(left[i], right[i]), res)
            
        return res
