class Solution:
    def removePalindromeSub(self, s: str) -> int:
        if len(s) == 0:
            return 0
        front = 0
        back = len(s) - 1
        isPalindromic = True
        
        while front < back:
            if s[front] != s[back]:
                isPalindromic = False
                break
            front += 1
            back -= 1
        
        if isPalindromic:
            return 1
        else:
            return 2
