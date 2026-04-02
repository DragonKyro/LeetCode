class Solution {
    public String stringHash(String s, int k) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i += k) {
            int total = 0;
            for (int j = i; j < i + k; j++) total += s.charAt(j) - 'a';
            sb.append((char)(total % 26 + 'a'));
        }
        return sb.toString();
    }
}
