class Solution {
    public int largestAltitude(int[] gain) {
        int altitude = 0, maxAlt = 0;
        for (int g : gain) {
            altitude += g;
            maxAlt = Math.max(maxAlt, altitude);
        }
        return maxAlt;
    }
}
