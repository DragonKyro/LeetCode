import java.util.*;

class Solution {
    public int numberOfWeakCharacters(int[][] properties) {
        Arrays.sort(properties, (a, b) -> a[0] != b[0] ? b[0] - a[0] : a[1] - b[1]);
        int count = 0, maxDef = 0;
        for (int[] p : properties) {
            if (p[1] < maxDef) count++;
            else maxDef = p[1];
        }
        return count;
    }
}
