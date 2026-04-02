class Solution {
    public int isWinner(int[] p1, int[] p2) {
        int s1 = score(p1), s2 = score(p2);
        return s1 > s2 ? 1 : s2 > s1 ? 2 : 0;
    }
    int score(int[] p) {
        int s = 0;
        for (int i = 0; i < p.length; i++) {
            int m = (i>=1&&p[i-1]==10)||(i>=2&&p[i-2]==10) ? 2 : 1;
            s += m * p[i];
        }
        return s;
    }
}
