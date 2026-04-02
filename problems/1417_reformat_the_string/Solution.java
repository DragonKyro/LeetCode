import java.util.*;

class Solution {
    public String reformat(String s) {
        List<Character> letters = new ArrayList<>(), digits = new ArrayList<>();
        for (char c : s.toCharArray()) {
            if (Character.isLetter(c)) letters.add(c);
            else digits.add(c);
        }
        if (Math.abs(letters.size() - digits.size()) > 1) return "";
        if (digits.size() > letters.size()) {
            List<Character> tmp = letters; letters = digits; digits = tmp;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < digits.size(); i++) {
            sb.append(letters.get(i));
            sb.append(digits.get(i));
        }
        if (letters.size() > digits.size()) sb.append(letters.get(letters.size() - 1));
        return sb.toString();
    }
}
