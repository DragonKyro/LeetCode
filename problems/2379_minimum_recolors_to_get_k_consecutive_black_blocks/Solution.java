class Solution {
    public int minimumRecolors(String blocks, int k) {
        int whites = 0;
        for (int i = 0; i < k; i++) if (blocks.charAt(i) == 'W') whites++;
        int minOps = whites;
        for (int i = k; i < blocks.length(); i++) {
            whites += (blocks.charAt(i) == 'W' ? 1 : 0) - (blocks.charAt(i-k) == 'W' ? 1 : 0);
            minOps = Math.min(minOps, whites);
        }
        return minOps;
    }
}
