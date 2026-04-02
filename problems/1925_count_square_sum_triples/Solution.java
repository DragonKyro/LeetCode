class Solution {
    public int countTriples(int n) {
        int count = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = a; b <= n; b++) {
                int cSq = a * a + b * b;
                int c = (int) Math.sqrt(cSq);
                if (c <= n && c * c == cSq) count += (a != b) ? 2 : 1;
            }
        }
        return count;
    }
}
