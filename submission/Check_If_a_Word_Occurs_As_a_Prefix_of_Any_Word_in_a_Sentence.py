class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words = sentence.split(' ')
        
        for i in range(len(words)):
            buffer = str()
            for c in words[i]:
                buffer = buffer + c
                if len(buffer) > len(searchWord):
                    break
                if buffer == searchWord:
                    return i + 1
                
        return -1
