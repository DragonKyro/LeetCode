class Solution {
    public int winningPlayerCount(int n, int[][] pick) {
        int[][] cnt = new int[n][11];
        for (int[] p : pick) cnt[p[0]][p[1]]++;
        int res = 0;
        for (int i = 0; i < n; i++) {
            boolean win = false;
            for (int j = 0; j <= 10; j++) if (cnt[i][j] > i) win = true;
            if (win) res++;
        }
        return res;
    }
}
