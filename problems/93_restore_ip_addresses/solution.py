class Solution:
    def restoreIpAddresses(self, s: str) -> list[str]:
        result: list[str] = []

        def backtrack(start: int, parts: list[str]) -> None:
            if len(parts) == 4:
                if start == len(s):
                    result.append('.'.join(parts))
                return
            for length in range(1, 4):
                if start + length > len(s):
                    break
                segment = s[start:start + length]
                if (segment[0] == '0' and length > 1) or int(segment) > 255:
                    continue
                backtrack(start + length, parts + [segment])

        backtrack(0, [])
        return result
