class Solution {
    public boolean escapeGhosts(int[][] ghosts, int[] target) {
        int myDist = Math.abs(target[0]) + Math.abs(target[1]);
        for (int[] g : ghosts)
            if (Math.abs(g[0] - target[0]) + Math.abs(g[1] - target[1]) <= myDist) return false;
        return true;
    }
}
