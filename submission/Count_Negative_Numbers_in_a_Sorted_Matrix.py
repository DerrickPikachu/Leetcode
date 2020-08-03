class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        res = 0
        
        for r in range(len(grid) - 1, -1, -1):
            for c in range(len(grid[r]) - 1, -1, -1):
                if grid[r][c] < 0:
                    res += 1
                else:
                    break
        
        return res
