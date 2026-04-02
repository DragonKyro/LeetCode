import java.util.*;

class Solution {
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        Set<Integer> result = new HashSet<>();
        for (int a = 1; a <= bound; a = (x == 1) ? bound + 1 : a * x)
            for (int b = 1; a + b <= bound; b = (y == 1) ? bound + 1 : b * y)
                result.add(a + b);
        return new ArrayList<>(result);
    }
}
