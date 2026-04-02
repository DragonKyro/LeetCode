class Solution {
    public boolean isSumEqual(String firstWord, String secondWord, String targetWord) {
        return val(firstWord) + val(secondWord) == val(targetWord);
    }
    private int val(String word) {
        int v = 0;
        for (char c : word.toCharArray()) v = v * 10 + (c - 'a');
        return v;
    }
}
