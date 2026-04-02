import java.util.*;

class Solution {
    public List<String> ambiguousCoordinates(String s) {
        s = s.substring(1, s.length() - 1);
        List<String> result = new ArrayList<>();
        for (int i = 1; i < s.length(); i++)
            for (String x : make(s.substring(0, i)))
                for (String y : make(s.substring(i)))
                    result.add("(" + x + ", " + y + ")");
        return result;
    }
    List<String> make(String s) {
        List<String> res = new ArrayList<>();
        for (int d = 1; d <= s.length(); d++) {
            String left = s.substring(0, d), right = s.substring(d);
            if ((left.equals("0") || !left.startsWith("0")) && !right.endsWith("0"))
                res.add(left + (right.isEmpty() ? "" : ".") + right);
        }
        return res;
    }
}
