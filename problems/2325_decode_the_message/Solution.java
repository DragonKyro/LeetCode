import java.util.*;

class Solution {
    public String decodeMessage(String key, String message) {
        Map<Character, Character> map = new HashMap<>();
        int idx = 0;
        for (char c : key.toCharArray()) {
            if (c != ' ' && !map.containsKey(c)) {
                map.put(c, (char)('a' + idx++));
            }
        }
        StringBuilder sb = new StringBuilder();
        for (char c : message.toCharArray()) sb.append(map.getOrDefault(c, c));
        return sb.toString();
    }
}
