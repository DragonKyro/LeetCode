class Solution {
    public int minDominoRotations(int[] tops, int[] bottoms) {
        int res = check(tops[0], tops, bottoms);
        if (res != -1) return res;
        return check(bottoms[0], tops, bottoms);
    }
    private int check(int target, int[] tops, int[] bottoms) {
        int rotTop = 0, rotBot = 0;
        for (int i = 0; i < tops.length; i++) {
            if (tops[i] != target && bottoms[i] != target) return -1;
            else if (tops[i] != target) rotTop++;
            else if (bottoms[i] != target) rotBot++;
        }
        return Math.min(rotTop, rotBot);
    }
}
