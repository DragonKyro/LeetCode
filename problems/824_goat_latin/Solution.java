class Solution {
    public String toGoatLatin(String sentence) {
        String vowels = "aeiouAEIOU";
        String[] words = sentence.split(" ");
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < words.length; i++) {
            if (i > 0) sb.append(' ');
            if (vowels.indexOf(words[i].charAt(0)) >= 0) sb.append(words[i]);
            else sb.append(words[i].substring(1)).append(words[i].charAt(0));
            sb.append("ma");
            for (int j = 0; j <= i; j++) sb.append('a');
        }
        return sb.toString();
    }
}
