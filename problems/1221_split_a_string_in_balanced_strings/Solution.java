class Solution {
    public int balancedStringSplit(String s) {
        int res = 0, balance = 0;
        for (char c : s.toCharArray()) {
            balance += c == 'L' ? 1 : -1;
            if (balance == 0) res++;
        }
        return res;
    }
}
