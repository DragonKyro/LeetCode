class Solution {
    public int distanceTraveled(int mainTank, int additionalTank) {
        int dist = 0;
        while (mainTank >= 5) { mainTank -= 5; dist += 50; if (additionalTank > 0) { mainTank++; additionalTank--; } }
        return dist + mainTank * 10;
    }
}
