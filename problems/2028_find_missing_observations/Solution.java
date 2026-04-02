class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int sum = 0;
        for (int r : rolls) sum += r;
        int total = mean * (rolls.length + n) - sum;
        if (total < n || total > 6 * n) return new int[0];
        int base = total / n, remainder = total % n;
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            result[i] = base + (i < remainder ? 1 : 0);
        }
        return result;
    }
}
