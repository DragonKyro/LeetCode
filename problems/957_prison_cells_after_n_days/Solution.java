import java.util.*;

class Solution {
    public int[] prisonAfterNDays(int[] cells, int n) {
        Map<String, Integer> seen = new HashMap<>();
        while (n > 0) {
            String state = Arrays.toString(cells);
            if (seen.containsKey(state)) n %= seen.get(state) - n;
            seen.put(state, n);
            if (n >= 1) {
                n--;
                int[] next = new int[8];
                for (int i = 1; i < 7; i++)
                    next[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
                cells = next;
            }
        }
        return cells;
    }
}
