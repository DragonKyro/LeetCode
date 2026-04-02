class Solution {
    public int smallestValue(int n) {
        while (true) {
            int s = 0, x = n;
            for (int d = 2; d * d <= x; d++) while (x % d == 0) { s += d; x /= d; }
            if (x > 1) s += x;
            if (s == n) return n;
            n = s;
        }
    }
}
