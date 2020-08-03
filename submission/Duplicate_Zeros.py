class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        offsetArr = list([]);
        offset = 0
        
        for i in range(0, len(arr)):
            if i + offset >= len(arr):
                break
            offsetArr.append(offset);
            if arr[i] == 0:
                offset = offset + 1;
            
        i = len(offsetArr) - 1
        while i >= 0:
            arr[i+offsetArr[i]] = arr[i]
            if arr[i] == 0 and i + offsetArr[i] + 1 < len(arr):
                arr[i+offsetArr[i]+1] = 0;
            i = i - 1
        
