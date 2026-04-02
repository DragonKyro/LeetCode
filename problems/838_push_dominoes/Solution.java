class Solution {
    public String pushDominoes(String dominoes) {
        int n = dominoes.length();
        int[] forces = new int[n];
        int f = 0;
        for (int i = 0; i < n; i++) {
            if (dominoes.charAt(i) == 'R') f = n;
            else if (dominoes.charAt(i) == 'L') f = 0;
            else f = Math.max(f - 1, 0);
            forces[i] += f;
        }
        f = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes.charAt(i) == 'L') f = n;
            else if (dominoes.charAt(i) == 'R') f = 0;
            else f = Math.max(f - 1, 0);
            forces[i] -= f;
        }
        StringBuilder sb = new StringBuilder();
        for (int x : forces) sb.append(x == 0 ? '.' : (x > 0 ? 'R' : 'L'));
        return sb.toString();
    }
}
