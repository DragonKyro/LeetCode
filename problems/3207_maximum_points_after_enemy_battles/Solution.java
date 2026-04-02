import java.util.*;

class Solution {
    public long maximumPoints(int[] enemyEnergies, int currentEnergy) {
        Arrays.sort(enemyEnergies);
        if (currentEnergy < enemyEnergies[0]) return 0;
        long total = currentEnergy;
        for (int i = 1; i < enemyEnergies.length; i++) total += enemyEnergies[i];
        return total / enemyEnergies[0];
    }
}
