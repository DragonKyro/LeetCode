class Solution:
    def videoStitching(self, clips: list[list[int]], time: int) -> int:
        clips.sort()
        ans = 0
        end = 0
        farthest = 0
        i = 0
        while end < time:
            while i < len(clips) and clips[i][0] <= end:
                farthest = max(farthest, clips[i][1])
                i += 1
            if farthest == end:
                return -1
            end = farthest
            ans += 1
        return ans
