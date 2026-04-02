class Solution:
    def suggestedProducts(self, products: list[str], searchWord: str) -> list[list[str]]:
        products.sort()
        res: list[list[str]] = []
        prefix = ''
        start = 0
        for c in searchWord:
            prefix += c
            import bisect
            start = bisect.bisect_left(products, prefix, start)
            matches: list[str] = []
            for i in range(start, min(start + 3, len(products))):
                if products[i].startswith(prefix):
                    matches.append(products[i])
                else:
                    break
            res.append(matches)
        return res
