class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        total = numBottles
        while numBottles >= numExchange:
            new_bottles = numBottles // numExchange
            total += new_bottles
            numBottles = new_bottles + numBottles % numExchange
        return total
