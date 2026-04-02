class Solution {
    public long maxEnergyBoost(int[] a, int[] b) {
        int n = a.length;
        long da = a[0], db = b[0];
        for (int i = 1; i < n; i++) {
            long na = Math.max(da + a[i], db);
            long nb = Math.max(db + b[i], da);
            da = na; db = nb;
        }
        return Math.max(da, db);
    }
}
