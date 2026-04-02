class Solution {
    public int vowelStrings(String[] words, int left, int right) {
        String v = "aeiou"; int cnt = 0;
        for (int i = left; i <= right; i++)
            if (v.indexOf(words[i].charAt(0))>=0 && v.indexOf(words[i].charAt(words[i].length()-1))>=0) cnt++;
        return cnt;
    }
}
