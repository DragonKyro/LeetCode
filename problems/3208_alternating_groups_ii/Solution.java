class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int n = colors.length, res = 0, cnt = 1;
        for (int i = 1; i < n + k - 1; i++) {
            if (colors[i%n] != colors[(i-1+n)%n]) cnt++;
            else cnt = 1;
            if (cnt >= k) res++;
        }
        return res;
    }
}
