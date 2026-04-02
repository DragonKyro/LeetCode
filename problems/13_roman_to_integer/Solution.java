import java.util.*;

class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> m = Map.of('I',1,'V',5,'X',10,'L',50,'C',100,'D',500,'M',1000);
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && m.get(s.charAt(i)) < m.get(s.charAt(i + 1))) {
                res -= m.get(s.charAt(i));
            } else {
                res += m.get(s.charAt(i));
            }
        }
        return res;
    }
}
