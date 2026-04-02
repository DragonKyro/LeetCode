class Solution {
    public int passThePillow(int n, int time) {
        int cycle = 2 * (n - 1);
        time %= cycle;
        return time < n ? time + 1 : 2 * n - 1 - time;
    }
}
