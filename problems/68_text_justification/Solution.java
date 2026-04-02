import java.util.*;

class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> result = new ArrayList<>();
        int i = 0;
        while (i < words.length) {
            int j = i, lineLen = 0;
            while (j < words.length && lineLen + words[j].length() + (j - i) <= maxWidth) {
                lineLen += words[j].length();
                j++;
            }
            int spaces = maxWidth - lineLen;
            int gaps = j - i - 1;
            StringBuilder sb = new StringBuilder();
            for (int k = i; k < j; k++) {
                sb.append(words[k]);
                if (k < j - 1) {
                    int spaceCount;
                    if (j == words.length) spaceCount = 1;
                    else spaceCount = spaces / gaps + (k - i < spaces % gaps ? 1 : 0);
                    for (int s = 0; s < spaceCount; s++) sb.append(' ');
                }
            }
            while (sb.length() < maxWidth) sb.append(' ');
            result.add(sb.toString());
            i = j;
        }
        return result;
    }
}
