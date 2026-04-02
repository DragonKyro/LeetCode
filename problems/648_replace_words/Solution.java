import java.util.*;

class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        Set<String> rootSet = new HashSet<>(dictionary);
        String[] words = sentence.split(" ");
        StringBuilder sb = new StringBuilder();
        for (String word : words) {
            String replaced = word;
            for (int i = 1; i <= word.length(); i++) {
                if (rootSet.contains(word.substring(0, i))) {
                    replaced = word.substring(0, i);
                    break;
                }
            }
            if (sb.length() > 0) sb.append(" ");
            sb.append(replaced);
        }
        return sb.toString();
    }
}
