class Solution {
    public int[] executeInstructions(int n, int[] startPos, String s) {
        int m = s.length();
        int[] result = new int[m];
        int[] dr = new int[128], dc = new int[128];
        dr['U'] = -1; dr['D'] = 1; dc['L'] = -1; dc['R'] = 1;
        for (int i = 0; i < m; i++) {
            int r = startPos[0], c = startPos[1], count = 0;
            for (int j = i; j < m; j++) {
                r += dr[s.charAt(j)];
                c += dc[s.charAt(j)];
                if (r >= 0 && r < n && c >= 0 && c < n) count++;
                else break;
            }
            result[i] = count;
        }
        return result;
    }
}
