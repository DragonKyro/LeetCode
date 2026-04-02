import java.util.*;

class Solution {
    public List<Integer> pathInZigZagTree(int label) {
        List<Integer> result = new ArrayList<>();
        int node = label;
        while (node >= 1) {
            result.add(node);
            int level = (int)(Math.log(node) / Math.log(2));
            int levelMax = (1 << (level + 1)) - 1;
            int levelMin = 1 << level;
            node = (levelMax + levelMin - node) / 2;
        }
        Collections.reverse(result);
        return result;
    }
}
