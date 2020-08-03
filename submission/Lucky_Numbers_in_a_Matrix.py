class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        minRow = [min(row) for row in matrix]
        maxCol = [max(col) for col in zip(*matrix)]
        return [minNum for minNum in minRow if minNum in maxCol]
