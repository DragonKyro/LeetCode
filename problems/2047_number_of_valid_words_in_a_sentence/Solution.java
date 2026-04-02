class Solution {
    public int countValidWords(String sentence) {
        int count = 0;
        for (String token : sentence.split("\\s+")) {
            if (token.isEmpty()) continue;
            if (isValid(token)) count++;
        }
        return count;
    }
    private boolean isValid(String token) {
        int hyphen = 0;
        for (int i = 0; i < token.length(); i++) {
            char c = token.charAt(i);
            if (Character.isDigit(c)) return false;
            if (c == '-') {
                hyphen++;
                if (hyphen > 1) return false;
                if (i == 0 || i == token.length() - 1) return false;
                if (!Character.isLetter(token.charAt(i - 1)) || !Character.isLetter(token.charAt(i + 1))) return false;
            }
            if ("!.,;".indexOf(c) >= 0 && i != token.length() - 1) return false;
        }
        return true;
    }
}
