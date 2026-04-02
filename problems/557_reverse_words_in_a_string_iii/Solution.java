class Solution {
    public String reverseWords(String s) {
        StringBuilder res = new StringBuilder();
        for (String word : s.split(" ")) {
            res.append(new StringBuilder(word).reverse()).append(" ");
        }
        return res.toString().trim();
    }
}
