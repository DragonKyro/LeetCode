class Solution {
    public int countArrangement(int n) {
        return backtrack(n, 1, 0);
    }
    private int backtrack(int n, int pos, int visited) {
        if (pos > n) return 1;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if ((visited & (1 << i)) == 0 && (i % pos == 0 || pos % i == 0)) {
                count += backtrack(n, pos + 1, visited | (1 << i));
            }
        }
        return count;
    }
}
