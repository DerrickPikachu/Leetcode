class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        res = []
        appeared = {}
        
        for word in words:
            for start in range(len(word)):
                buffer = ""
                for end in range(start, len(word)):
                    buffer = buffer + word[end]
                    if buffer in appeared:
                        appeared[buffer] += 1
                    else:
                        appeared[buffer] = 1
                        
        for word in words:
            if appeared[word] > 1:
                res.append(word)
                
        return res
