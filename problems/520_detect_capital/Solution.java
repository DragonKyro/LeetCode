class Solution {
    public boolean detectCapitalUse(String word) {
        int caps = 0;
        for (char c : word.toCharArray()) if (Character.isUpperCase(c)) caps++;
        return caps == word.length() || caps == 0 || (caps == 1 && Character.isUpperCase(word.charAt(0)));
    }
}
