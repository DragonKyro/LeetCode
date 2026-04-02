from typing import List


class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        mp = {p[0]: p for p in pieces}
        i = 0
        while i < len(arr):
            if arr[i] not in mp:
                return False
            piece = mp[arr[i]]
            for val in piece:
                if i >= len(arr) or arr[i] != val:
                    return False
                i += 1
        return True
