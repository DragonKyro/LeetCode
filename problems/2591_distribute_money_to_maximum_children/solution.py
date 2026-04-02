class Solution:
    def distMoney(self, money: int, children: int) -> int:
        money -= children
        if money < 0: return -1
        ans = min(money // 7, children)
        money -= ans * 7
        if (ans == children and money > 0) or (ans == children - 1 and money == 3):
            ans -= 1
        return max(ans, 0)
