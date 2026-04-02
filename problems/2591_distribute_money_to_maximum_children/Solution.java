class Solution {
    public int distMoney(int money, int children) {
        money -= children;
        if (money < 0) return -1;
        int ans = Math.min(money / 7, children);
        money -= ans * 7;
        if ((ans == children && money > 0) || (ans == children - 1 && money == 3)) ans--;
        return Math.max(ans, 0);
    }
}
