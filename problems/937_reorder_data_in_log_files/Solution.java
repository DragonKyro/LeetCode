import java.util.*;

class Solution {
    public String[] reorderLogFiles(String[] logs) {
        List<String> letters = new ArrayList<>(), digits = new ArrayList<>();
        for (String log : logs) {
            if (Character.isDigit(log.split(" ")[1].charAt(0))) digits.add(log);
            else letters.add(log);
        }
        letters.sort((a, b) -> {
            String bodyA = a.substring(a.indexOf(' ') + 1);
            String bodyB = b.substring(b.indexOf(' ') + 1);
            int cmp = bodyA.compareTo(bodyB);
            return cmp != 0 ? cmp : a.compareTo(b);
        });
        letters.addAll(digits);
        return letters.toArray(new String[0]);
    }
}
