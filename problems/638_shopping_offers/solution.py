class Solution:
    def shoppingOffers(self, price: list[int], special: list[list[int]], needs: list[int]) -> int:
        from functools import lru_cache
        def dfs(needs_tuple):
            needs = list(needs_tuple)
            cost = sum(needs[i] * price[i] for i in range(len(price)))
            for offer in special:
                new_needs = []
                valid = True
                for i in range(len(price)):
                    if needs[i] < offer[i]:
                        valid = False
                        break
                    new_needs.append(needs[i] - offer[i])
                if valid:
                    cost = min(cost, offer[-1] + dfs(tuple(new_needs)))
            return cost
        return dfs(tuple(needs))
