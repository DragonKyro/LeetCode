class Solution {
    public boolean isValid(String word) {
        if (word.length() < 3) return false;
        boolean v = false, c = false;
        for (char ch : word.toCharArray()) {
            if (!Character.isLetterOrDigit(ch)) return false;
            if (Character.isLetter(ch)) {
                if ("aeiouAEIOU".indexOf(ch) >= 0) v = true;
                else c = true;
            }
        }
        return v && c;
    }
}
