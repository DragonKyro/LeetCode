class Solution:
    def exclusiveTime(self, n: int, logs: list[str]) -> list[int]:
        result = [0] * n
        stack = []
        prev_time = 0
        for log in logs:
            parts = log.split(':')
            fid, typ, time = int(parts[0]), parts[1], int(parts[2])
            if typ == 'start':
                if stack:
                    result[stack[-1]] += time - prev_time
                stack.append(fid)
                prev_time = time
            else:
                result[stack.pop()] += time - prev_time + 1
                prev_time = time + 1
        return result
