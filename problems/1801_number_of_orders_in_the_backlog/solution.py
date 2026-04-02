from typing import List


class Solution:
    def getNumberOfBacklogOrders(self, orders: List[List[int]]) -> int:
        import heapq
        MOD = 10**9 + 7
        buy = []  # max heap (negate)
        sell = []  # min heap
        for price, amount, order_type in orders:
            if order_type == 0:
                heapq.heappush(buy, (-price, amount))
            else:
                heapq.heappush(sell, (price, amount))
            while buy and sell and -buy[0][0] >= sell[0][0]:
                bp, ba = heapq.heappop(buy)
                sp, sa = heapq.heappop(sell)
                matched = min(ba, sa)
                if ba - matched > 0:
                    heapq.heappush(buy, (bp, ba - matched))
                if sa - matched > 0:
                    heapq.heappush(sell, (sp, sa - matched))
        total = 0
        for _, amount in buy:
            total = (total + amount) % MOD
        for _, amount in sell:
            total = (total + amount) % MOD
        return total
