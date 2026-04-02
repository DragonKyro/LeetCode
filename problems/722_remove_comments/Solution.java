import java.util.*;

class Solution {
    public List<String> removeComments(String[] source) {
        List<String> result = new ArrayList<>();
        boolean inBlock = false;
        StringBuilder newLine = new StringBuilder();
        for (String line : source) {
            int i = 0;
            if (!inBlock) newLine = new StringBuilder();
            while (i < line.length()) {
                if (!inBlock && i + 1 < line.length() && line.charAt(i) == '/' && line.charAt(i+1) == '*') {
                    inBlock = true; i += 2;
                } else if (inBlock && i + 1 < line.length() && line.charAt(i) == '*' && line.charAt(i+1) == '/') {
                    inBlock = false; i += 2;
                } else if (!inBlock && i + 1 < line.length() && line.charAt(i) == '/' && line.charAt(i+1) == '/') {
                    break;
                } else if (!inBlock) {
                    newLine.append(line.charAt(i++));
                } else { i++; }
            }
            if (!inBlock && newLine.length() > 0) result.add(newLine.toString());
        }
        return result;
    }
}
