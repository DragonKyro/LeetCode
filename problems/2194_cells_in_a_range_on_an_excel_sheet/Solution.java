import java.util.*;

class Solution {
    public List<String> cellsInRange(String s) {
        List<String> result = new ArrayList<>();
        for (char c = s.charAt(0); c <= s.charAt(3); c++) {
            for (char r = s.charAt(1); r <= s.charAt(4); r++) {
                result.add("" + c + r);
            }
        }
        return result;
    }
}
