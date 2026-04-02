class Solution {
    public int minimumPartition(String s, int k) {
        int parts = 1; long cur = 0;
        for (char c : s.toCharArray()) {
            int d = c - '0'; if (d > k) return -1;
            cur = cur * 10 + d;
            if (cur > k) { parts++; cur = d; }
        }
        return parts;
    }
}
