class Solution {
    public boolean areSentencesSimilar(String sentence1, String sentence2) {
        String[] w1 = sentence1.split(" "), w2 = sentence2.split(" ");
        if (w1.length > w2.length) { String[] tmp = w1; w1 = w2; w2 = tmp; }
        int n1 = w1.length, n2 = w2.length;
        int left = 0;
        while (left < n1 && w1[left].equals(w2[left])) left++;
        int right = 0;
        while (right < n1 - left && w1[n1 - 1 - right].equals(w2[n2 - 1 - right])) right++;
        return left + right >= n1;
    }
}
