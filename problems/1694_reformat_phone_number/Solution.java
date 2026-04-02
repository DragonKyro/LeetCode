import java.util.*;

class Solution {
    public String reformatNumber(String number) {
        String digits = number.replace(" ", "").replace("-", "");
        List<String> groups = new ArrayList<>();
        int i = 0;
        while (digits.length() - i > 4) {
            groups.add(digits.substring(i, i + 3));
            i += 3;
        }
        int remaining = digits.length() - i;
        if (remaining <= 3) {
            groups.add(digits.substring(i));
        } else {
            groups.add(digits.substring(i, i + 2));
            groups.add(digits.substring(i + 2));
        }
        return String.join("-", groups);
    }
}
