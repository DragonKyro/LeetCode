class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        def isIPv4(s: str) -> bool:
            parts = s.split('.')
            if len(parts) != 4:
                return False
            for part in parts:
                if not part or not part.isdigit() or (len(part) > 1 and part[0] == '0') or int(part) > 255:
                    return False
            return True

        def isIPv6(s: str) -> bool:
            parts = s.split(':')
            if len(parts) != 8:
                return False
            for part in parts:
                if not part or len(part) > 4:
                    return False
                for c in part:
                    if c not in '0123456789abcdefABCDEF':
                        return False
            return True

        if isIPv4(queryIP):
            return 'IPv4'
        if isIPv6(queryIP):
            return 'IPv6'
        return 'Neither'
