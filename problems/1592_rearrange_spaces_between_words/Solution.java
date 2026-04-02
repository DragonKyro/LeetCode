class Solution {
    public String reorderSpaces(String text) {
        int spaces = 0;
        for (char c : text.toCharArray()) if (c == ' ') spaces++;
        String[] words = text.trim().split("\\s+");
        if (words.length == 1) return words[0] + " ".repeat(spaces);
        int gap = spaces / (words.length - 1);
        int extra = spaces % (words.length - 1);
        return String.join(" ".repeat(gap), words) + " ".repeat(extra);
    }
}
